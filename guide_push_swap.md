# GUIDE COMPLET DE RÉALISATION : PUSH_SWAP V1.0 (2025)
## Architecture : Tableaux Circulaires | Objectif : Performance & Simplicité
**École 42 - Projet de Groupe**

---

## 1. AVANT DE CODER : CONCEPTS CLÉS

### Pourquoi les Tableaux Circulaires ?
Plutôt que des listes chaînées (`malloc` pour chaque nœud), on utilise un seul tableau d'entiers alloué au départ.
* **Performance :** Mémoire contiguë (Cache Friendly).
* **Rapidité :** Les rotations (`ra`, `rra`) se font en $O(1)$ en changeant juste l'index de "tête" (`head`), sans déplacer aucune donnée.
* **Gestion :** Pas de `next` ou `prev` à gérer, juste des maths modulo.

### La Normalisation (Ranking)
**Crucial pour la performance.** On ne trie pas les valeurs brutes (ex: `-2147483648`, `42`, `0`).
On trie leur **rang**.
* Exemple entrée : `100, -50, 10`
* Devient en interne : `2, 0, 1` (0 est le plus petit, 2 le plus grand).
* **Avantage :** Permet d'utiliser le **Radix Sort** (base binaire) très facilement car tous les nombres sont positifs et bornés par `size`.

---

## 2. ARCHITECTURE DES FICHIERS & DONNÉES

### Structure de Données (`push_swap.h`)
```c
typedef struct s_stack
{
    int     *values;      // Le tableau contenant les rangs
    int     head;         // Index du "haut" de la pile
    int     tail;         // Index du "bas" de la pile (où on écrit le prochain)
    int     size;         // Nombre d'éléments actuels
    int     capacity;     // Taille max allouée (nb total d'args)
    char    name;         // 'a' ou 'b' (pour l'affichage)
} t_stack;

typedef struct s_data
{
    t_stack a;
    t_stack b;
    int     total_ops;    // Compteur d'opérations
    int     is_bench;     // 1 si flag --bench actif
} t_data;

```

### Liste des Fichiers Sugguérée (~12 fichiers)

#### 1. Main & Init

* `main.c` : Point d'entrée. Gestion des flags (`--simple`, `--bench`, etc.). Nettoyage final.
* `init.c` : `init_stacks` (malloc), `parse_args` (atoi + check errors), `rank_values` (normalisation).
* `clean.c` : `free_data`, `error_exit`.

#### 2. Primitives Circulaires (Le Moteur)

* `stack_utils.c` : `push_circular`, `pop_circular`, `get_val_at_index`.
* `ops_swap_push.c` : `sa`, `sb`, `ss`, `pa`, `pb`.
* `ops_rotate.c` : `ra`, `rb`, `rr` (incrémente head).
* `ops_rev_rotate.c` : `rra`, `rrb`, `rrr` (décrémente head).

#### 3. Métriques & Analyse

* `metrics.c` : Calcul du `disorder` (Mandatory).
* `benchmark.c` : Affichage des stats sur `stderr`.

#### 4. Algorithmes (Les Stratégies)

* `sort_small.c` : Cas simples (3 à 5 nombres).
* `sort_medium.c` : Algo des "Chunks" ().
* `sort_complex.c` : Radix Sort Binaire ().
* `sort_adaptive.c` : Le sélecteur intelligent.

---

## 3. LOGIQUE MATHÉMATIQUE (CIRCULAR BUFFER)

L'accès à un élément `i` (du point de vue logique, où 0 est le haut) se fait ainsi :

```c
// Récupérer la valeur logique i (0 = top, size-1 = bottom)
int get_val(t_stack *s, int i)
{
    return (s->values[(s->head + i) % s->capacity]);
}

```

* **Rotate (`ra`)** : `head = (head + 1) % capacity`
* **Rev Rotate (`rra`)** : `head = (head - 1 + capacity) % capacity`

---

## 4. GUIDE DE RÉALISATION : ÉTAPE PAR ÉTAPE

### Étape 1 : Parsing & Ranking (Fondations)

1. **Parsing :** Récupérer les arguments. Gérer le cas chaîne unique (`"1 2 3"`).
2. **Checks :** Vérifier qu'il n'y a que des chiffres. Vérifier `MAX_INT` / `MIN_INT` (utiliser `long long`).
3. **Doublons :** Mettre les valeurs dans un tableau temporaire `tmp`. Trier `tmp` (ex: bubble sort). Vérifier `tmp[i] == tmp[i+1]`.
4. **Ranking :** Remplir `stack_a` non pas avec les valeurs, mais avec leur position dans `tmp`.
* `valeur_originale` -> `index_trie`
* A = `[50, -2, 10]` -> A devient `[2, 0, 1]`



### Étape 2 : Les Opérations (Moteur)

Implémentez les 11 opérations.

* Créez une fonction helper `op(t_data *d, char *op_name)` qui :
1. Exécute l'action.
2. Incrémente `total_ops`.
3. Affiche `op_name` sur stdout **SAUF** si `d->is_bench == 1`.



### Étape 3 : Calcul du Désordre (Métrique)

Implémentez la formule obligatoire :

```c
float compute_disorder(t_stack *a)
{
    long mistakes = 0;
    long total = 0;
    
    // Double boucle sur la taille ACTUELLE de A
    for (int i = 0; i < a->size; i++) {
        for (int j = i + 1; j < a->size; j++) {
            total++;
            if (get_val(a, i) > get_val(a, j)) // Plus grand avant plus petit
                mistakes++;
        }
    }
    if (total == 0) return (0.0f);
    return ((float)mistakes / total);
}

```

### Étape 4 : Les Stratégies de Tri

#### A. Stratégie Simple (`--simple`)

* **3 nombres :** Hardcodez les cas (ex: si `2 1 3` -> `sa`). Max 2 coups.
* **5 nombres :** Poussez les deux plus petits (`0` et `1` grâce au ranking) vers B. Triez les 3 restants. Ramenez B.

#### B. Stratégie Medium (`--medium`) : Les Chunks

* Divisez vos rangs en blocs. Exemple pour 100 nombres, 5 chunks de 20.
* **Phase 1 (A -> B) :**
* Tant que A n'est pas vide : Si `top` fait partie du Chunk actuel ou précédent -> `pb`. Sinon `ra`.
* *Optimisation :* Si vous pushez un nombre du chunk *précédent*, faites `rb` pour le mettre en bas de B (forme de sablier).


* **Phase 2 (B -> A) :**
* Trouvez le rang maximum dans B.
* Ramenez-le en haut de B (calculez le chemin le plus court entre `rb` et `rrb`).
* `pa`.



#### C. Stratégie Complex (`--complex`) : Radix Binaire

Le plus efficace pour le ratio temps_dev / performance.

1. Déterminez le nombre de bits max (`max_bits`) pour représenter `size`.
2. Boucle `for (bit = 0; bit < max_bits; bit++)` :
* Boucle sur tous les éléments de A :
* Si `(val >> bit) & 1` est 0 -> `pb`.
* Sinon -> `ra`.


* Vider B vers A : `while (b->size) pa`.


3. À la fin, la liste est triée.

#### D. Stratégie Adaptive (`--adaptive`)

Dans `main.c` ou `sort_adaptive.c` :

1. Calculez `disorder`.
2. Si `disorder < 0.2` : Tentez un tri simple ou une passe de "Bubble Sort optimisé pour stacks".
3. Si `0.2 <= disorder < 0.5` : Lancez Medium (Chunks).
4. Si `disorder >= 0.5` : Lancez Complex (Radix).

### Étape 5 : Le Benchmark (`--bench`)

* Si le flag est présent, n'imprimez RIEN sur stdout.
* À la fin du tri, écrivez sur `stderr` (fd 2) :
* Disorder initial.
* Stratégie utilisée.
* Total opérations.
* Détail (comptez les `sa`, `ra`, etc. dans votre structure `t_data`).



---

## 5. OPTIMISATIONS & CHECKLIST FINALE

### Objectifs Performance

* **100 nombres :** < 700 ops. (Radix de base fait ~800, Chunks bien réglés font ~600).
* **500 nombres :** < 5500 ops. (Radix fait ~5000, Chunks ~4500).

### Checklist "Norminette & Defense"

1. [ ] **Makefile :** Pas de relink.
2. [ ] **Leaks :** `valgrind ./push_swap 1 2 3` -> "All heap blocks were freed".
3. [ ] **Erreurs :** `./push_swap "une string"` -> Affiche "Error\n" sur stderr.
4. [ ] **Vide :** `./push_swap` (sans args) -> Ne rien afficher, rendre le prompt.
5. [ ] **Headers :** Protection contre la double inclusion (`#ifndef PUSH_SWAP_H`).
6. [ ] **Binôme :** Les deux logins sont dans le dépôt.

### Astuce Ultime pour le Radix

Si le Radix pur dépasse légèrement 700 ops pour 100 nombres :
Utilisez la **Base 3 ou 4** au lieu de la Base 2 (Binaire). Cela réduit le nombre de passes (boucles externes), mais demande un peu plus de logique pour gérer les "buckets" dans B. Pour valider le projet simplement, le Radix Base 2 suffit souvent pour la note "Good", les Chunks sont mieux pour "Excellent" sur 100.

```

```