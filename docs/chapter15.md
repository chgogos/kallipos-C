# 15. Αποσφαλμάτωση

<i>Σύνοψη</i> Αποσφαλμάτωση κώδικα, στατικά assertions, assertions χρόνου εκτέλεσης, αποσφαλμάτωση με <span class="p-style">printf()</span>, το GDB, βασικές δυνατότητες και παραδείγματα χρήσης του GDB.

<i>Προαπαιτούμενη γνώση</i> Τύποι δεδομένων, είσοδος/έξοδος, δομές επιλογής και επανάληψης, συναρτήσεις, πίνακες, δείκτες, αλφαριθμητικά.

## 15.1 Εισαγωγή περί αποσφαλμάτωσης

Η αποσφαλμάτωση ενός προγράμματος είναι η διαδικασία κατά την οποία γίνεται προσπάθεια διόρθωσης κώδικα που επιδεικνύει συμπεριφορά διαφορετική από την επιθυμητή. Σε αυτό το κεφάλαιο θα παρουσιαστούν τρεις τρόποι με τους οποίους μπορεί να υποβοηθηθεί η αποσφαλμάτωση κώδικα, πρώτα με χρήση assertions, μετά με χρήση απλών εντολών εμφάνισης αποτελεσμάτων κατά την εκτέλεση του προγράμματος και τέλος με
χρήση του λογισμικού GDB (1).  
{ .annotate }

1. <a href="https://www.sourceware.org/gdb/" target="_blank">https://www.sourceware.org/gdb/</a>

Με δεδομένο ότι η αποσφαλμάτωση είναι μια δύσκολη διαδικασία που δεν διδάσκεται τυπικά όπως άλλα αντικείμενα της επιστήμης υπολογιστών (π.χ. αλγόριθμοι, δομές δεδομένων, γλώσσες προγραμματισμού, βάσεις δεδομένων κ.λπ.) είναι σημαντικό να επισημανθεί ότι η χρήση και μόνο εργαλείων δεν οδηγεί στην απόκτηση ικανότητας αποτελεσματικής αποσφαλμάτωσης. Όπως αναφέρει και ο Devon H. O’Dell στο άρθρο του “The Debugging Mindset” [^1], οι προγραμματιστές θα πρέπει να συνηθίσουν να χρησιμοποιούν την αποσφαλμάτωση ως έναν τρόπο εξάσκησης στη δεξιότητα της επίλυσης προβλημάτων. Αυτό μπορεί να υποβοηθηθεί από εργαλεία όπως αυτά που θα περιγραφούν στη συνέχεια, αλλά πρέπει να υποστηριχθεί από επιμονή, συνέπεια στην προσπάθεια εμβάθυνσης σε δύσκολες έννοιες και ανάπτυξη της περιέργειας για τον τρόπο με τον οποίο λειτουργεί η εκάστοτε γλώσσα προγραμματισμού και ο υπολογιστής. Ενδιαφέρουσα και διασκεδαστική είναι και η προσέγγιση στην αποσφαλμάτωση που περιγράφει η Julian Evans στο “A Debugging Manifesto” [^2].

## 15.2 Assertions

Ένα assertion (διαβεβαίωση) είναι ένας μηχανισμός με τον οποίο ελέγχεται ότι μια συνθήκη ικανοποιείται σε ένα συγκεκριμένο σημείο του κώδικα. Γενικά πρόκειται για ελέγχους καταστάσεων που δεν θα έπρεπε να προκύπτουν και οι οποίες αν για κάποιον λόγο εμφανιστούν, ο κώδικας που ακολουθεί είναι πιθανό να παρουσιάσει μη ορθή συμπεριφορά. Για να χρησιμοποιηθούν assertions σε έναν κώδικα θα πρέπει να συμπεριληφθεί το αρχείο επικεφαλίδας <span class="p-style">assert.h</span>. Υπάρχουν δύο ειδών assertions, τα στατικά τα οποία ελέγχονται κατά τη μεταγλώττιση με τη μακροεντολή <span class="p-style">static_assert()</span> και τα assertions χρόνου εκτέλεσης που ελέγχονται με τη μακροεντολή <span class="p-style">assert()</span>.

### 15.2.1 Στατικά assertions

Η μακροεντολή static_assert() μπορεί να χρησιμοποιηθεί με τον ακόλουθο τρόπο:

```
static_assert(integer ‐constant ‐expression , string);
```
Η ακέραια έκφραση (<span class="p-style">integer‐constant‐expression</span>) πρέπει να είναι σταθερή και αν λάβει τιμή που δεν είναι μηδέν, τότε προκύπτει σφάλμα μεταγλώττισης με διαγνωστικό μήνυμα το κείμενο της δεύτερης παραμέτρου. Τα στατικά assertions εισήχθησαν με την C11 και αφορούν ελέγχους που μπορούν να εντοπιστούν κατά τη μεταγλώττιση. Για τον λόγο αυτό η ακέραια έκφραση που ελέγχεται θα πρέπει να είναι σταθερή. Αξίζει να σημειωθεί ότι η μακροεντολή <span class="p-style">static_assert()</span> καλεί τη <span class="p-style">_Static_assert()</span> (το <span class="p-style">_Static_assert</span> είναι keyword στη C11) με τις ίδιες παραμέτρους, οπότε το <span class="p-style">_Static_assert()</span> μπορεί να χρησιμοποιηθεί εναλλακτικά στη θέση του <span class="p-style">static_assert()</span>.  
Στον κώδικα 15.1 παρουσιάζεται ένα παράδειγμα στο οποίο ελέγχεται η ακέραια τιμή που λαμβάνει μια συμβολική σταθερά που ορίζεται σε ένα <span class="p-style">enum</span>.

```{.c title="Κώδικας 15.1: ch15_p1.c - παράδειγμα χρήσης του static_assert()." linenums="1"}
--8<-- "src/ch15_p1.c"
```

Λόγω του ότι υπάρχει ασυμφωνία στην ακέραια τιμή στην οποία αντιστοιχεί το στοιχείο <span class="p-style">GREEN</span> (λαμβάνει την τιμή 3, ενώ το <span class="p-style">static_assert()</span> υποθέτει ότι η τιμή του θα έπρεπε να είναι 2), ο μεταγλωττιστής θα εμφανίσει το ακόλουθο μήνυμα λάθους:

```
$ gcc ch15_p1.c
In file included from ch15_p1.c:1:
ch15_p1.c: In function 'main':
ch15_p1.c:10:3: error: static assertion failed: "I expect GREEN to be 2"
   10 | static_assert(GREEN == 2, "I expect GREEN to be 2");
      | ^~~~~~~~~~~~~
```

Ένα ακόμη παράδειγμα με στατικό assertion παρουσιάζεται στον κώδικα 15.2 που ελέγχει ότι το μέγεθος του τύπου <span class="p-style">int</span> στο υπολογιστικό σύστημα όπου γίνεται η μεταγλώττιση είναι 4 bytes.

```{.c title="Κώδικας 15.2: ch15_p2.c - έλεγχος ότι ο τύπος int καταλαμβάνει 4 bytes." linenums="1"}
--8<-- "src/ch15_p2.c"
```

Αν το μέγεθος τύπου <span class="p-style">int</span> είναι όντως 4 bytes (όπως τυπικά συμβαίνει στα συστήματα αρχιτεκτονικής 64bits), τότε η μεταγλώττιση θα ολοκληρωθεί χωρίς την επιστροφή κάποιου μηνύματος όπως στη συνέχεια:

```
$ gcc ch15_p2.c
```

Αν όμως η μεταγλώττιση γίνει σε ένα σύστημα με αρχιτεκτονική 32bits, όπου τυπικά το μέγεθος των <span class="p-style">int</span> είναι 2 bytes, θα εμφανιστεί το ακόλουθο (ή παρόμοιο) μήνυμα:

```
$ gcc ch15_p2.c
ch15_p2b.c:4:29: note: expression evaluates to '2 == 4'
  static_assert(sizeof(int) == 4, "int should be 4 bytes");
```

### 15.2.2 Assertions χρόνου εκτέλεσης 

Τα assertions χρόνου εκτέλεσης γράφονται με τη χρήση της μακροεντολής <span class="p-style">assert()</span> η οποία καλείται ως εξής:

```
assert(expression);
```

Αν η έκφραση <span class="p-style">expression</span> είναι ίση με το μηδέν, τότε εμφανίζεται ένα μήνυμα με το όνομα του αρχείου πηγαίου κώδικα, τον αριθμό γραμμής εντολής και τη συνάρτηση μέσα στην οποία βρίσκεται το assertion και το πρόγραμμα τερματίζει. Το σκεπτικό είναι ότι με αυτόν τον τρόπο μπορούν να ελέγχονται τα ορίσματα που περνούν σε συναρτήσεις έτσι ώστε οι συναρτήσεις που καλούνται με μη έγκυρες τιμές να τερματίζουν την εκτέλεση του προγράμματος και ο προγραμματιστής να ενημερώνεται για το πρόβλημα.  
Τα assertions χρόνου εκτέλεσης συνήθως χρησιμοποιούνται για βασικούς ελέγχους όπως η αποφυγή τιμών που δεν έχουν νόημα για τη συνέχεια της εκτέλεσης, όπως για παράδειγμα ο έλεγχος του εάν ένας δείκτης είναι <span class="p-style">NULL</span> και πρόκειται να γίνει αποαναφορά του, το εάν μια μεταβλητή δεικτοδότησης σε στοιχείο πίνακα λαμβάνει τιμή εντός των ορίων μεγέθους του πίνακα (από 0 μέχρι Ν-1) πριν χρησιμοποιηθεί και άλλα. Στο παράδειγμα που ακολουθεί στον κώδικα 15.3, το assertion διασφαλίζει ότι η τιμή που εισάγεται ως αριθμός ημέρας του Ιανουαρίου θα είναι έγκυρη τιμή (δηλαδή από 1 έως και 31). Στον ίδιο κώδικα χρησιμοποιείται το «κόλπο» της προσθήκης με το <span class="p-style">&&</span> (λογικό τελεστή σύζευξης) ενός αλφαριθμητικού στην έκφραση που εξετάζεται. Το αλφαριθμητικό αυτό θα εμφανίζεται στο διαγνωστικό μήνυμα εφόσον ενεργοποιείται το assertion. Ο λόγος για τον οποίο συμβαίνει αυτό είναι διότι τα λεκτικά αποτιμώνται ως μη μηδενικά (true), οπότε η προσθήκη με το <span class="p-style">&&</span> όρων δεν έχει επίδραση στην τιμή της λογικής έκφρασης. Άρα, το αποτέλεσμα είναι ότι όταν εμφανιστεί το διαγνωστικό μήνυμα από το <span class="p-style">assert()</span> θα εμφανιστεί και το αλφαριθμητικό που έχει προστεθεί στο τέλος της γραμμής 8 του κώδικα.


```{.c title="Κώδικας 15.3: ch15_p3.c - έλεγχος ότι ο αριθμός ημέρας που εισάγει ο χρήστης είναι από 1 μέχρι και 31." linenums="1"}
--8<-- "src/ch15_p3.c"
```
Το αποτέλεσμα της εκτέλεσης του παραπάνω κώδικα με είσοδο μια μη έγκυρη τιμή (π.χ. 32) είναι το ακόλουθο:

```
Input a month day for January: 32
Assertion failed: (d >= 1 && d <= 31) && "month day should be from 1 to 31", file
    ↪ ch15_p3.c, line 8
```
Ο έλεγχος των assertions χρόνου εκτέλεσης μπορεί να απενεργοποιηθεί με την ακόλουθη εντολή του προεπεξεργαστή:

```{.c}
#define NDEBUG
```
Συνεπώς, ο κώδικας μπορεί να περιέχει assertions χρόνου εκτέλεσης που θα είναι χρήσιμα κατά την ανάπτυξη και τη διόρθωσή του και την παραπάνω εντολή σε σχόλια, έτσι ώστε να μην είναι ενεργή. Πριν δημιουργηθεί το τελικό εκτελέσιμο, το οποίο θα χρησιμοποιηθεί από τον χρήστη του προγράμματος, μπορεί να ενεργοποιηθεί η παραπάνω εντολή, αφαιρώντας τους χαρακτήρες που την καθιστούσαν σχόλιο, έτσι ώστε το τελικό εκτελέσιμο να μην λαμβάνει υπόψη τα assertions χρόνου εκτέλεσης. Θα πρέπει να σημειωθεί ότι κάτι τέτοιο μπορεί να είναι επικίνδυνο καθώς μη έγκυρες είσοδοι, εξάντληση διαθέσιμης μνήμης, σφάλματα σε άνοιγμα αρχείων κ.λπ. ενδεχόμενα δεν θα εξετάζονται στο εκτελέσιμο που θα παραδοθεί στον χρήστη.

## 15.3 Αποσφαλμάτωση με printf()

O Brian Kernighan στο βιβλίο του “Unix for programmers” του 1979, αναφέρει ότι «ο πλέον αποδοτικός τρόπος αποσφαλμάτωσης είναι η προσεκτική σκέψη σε συνδυασμό με συνετά τοποθετημένες εντολές εκτύπωσης». Τα τελευταία χρόνια η τεχνική της αποσφαλμάτωσης με εντολές print ή log έχει γίνει γνωστή ως caveman debugging (αποσφαλμάτωση του ανθρώπου των σπηλαίων) και θεωρείται ως ένας χρήσιμος μεν αλλά απλοϊκός και σχετικά χονδροειδής τρόπος αποσφαλμάτωσης. Ωστόσο, η ευκολία χρήσης κλήσεων της <span class="p-style">printf()</span>, που αποκαλύπτουν τιμές μεταβλητών και εκφράσεων σε κρίσιμα σημεία της εκτέλεσης του προγράμματος εξακολουθεί να είναι ένας αποτελεσματικός τρόπος εντοπισμού λαθών και κατανόησης του προγράμματος.  
Οι ακόλουθες μακροεντολές μπορούν να βοηθήσουν στην εμφάνιση χρήσιμων μηνυμάτων: <span class="p-style">\_\_FILE__, \_\_LINE__, \_\_func__</span>. Η <span class="p-style">\_\_FILE__</span> επιστρέφει το όνομα αρχείου στο οποίο βρίσκεται ο πηγαίος κώδικας, η <span class="p-style">\_\_LINE__</span> τη γραμμή στην οποία εντοπίζεται η κλήση της <span class="p-style">printf()</span> που την περιέχει και η <span class="p-style">\_\_func__</span> τη συνάρτηση μέσα από την οποία καλείται η <span class="p-style">printf()</span>. Ο κώδικας 15.4 παρουσιάζει ένα απλό παράδειγμα όπου καλείται μια συνάρτηση και εμφανίζονται πληροφορίες που επιστρέφουν οι μακροεντολές που αναφέρθηκαν.

```{.c title="Κώδικας 15.4: ch15_p4.c - απλή μέθοδος αποσφαλμάτωσης με χρήση της printf() και ειδικών μακροεντολων που επιστρέφουν πληροφορίες για τη γραμμή κώδικα που εκτελείται." linenums="1"}
--8<-- "src/ch15_p4.c"
```

Κατά την εκτέλεση του προγράμματος θα εμφανιστεί η ακόλουθη έξοδος:

```
File:ch15_p4.c Function:fun Line:4 a=42
```

## 15.4 Αποσφαλμάτωση με debugger

Η χρήση ενός λογισμικού αποσφαλμάτωσης (debugger) μπορεί να βοηθήσει στη διόρθωση δύσκολων στον εντοπισμό σφαλμάτων. Επιτρέπει την εκτέλεση του κώδικα εντολή προς εντολή και την παρακολούθηση τόσο της κατάστασης της στοίβας χρόνου εκτέλεσης (δηλαδή, ποια συνάρτηση έχει κληθεί από ποια συνάρτηση), όσο και των τιμών των ενεργών μεταβλητών. Επιπλέον, ο debugger επιτρέπει τον ορισμό breakpoints (σημείων διακοπής εκτέλεσης) και watches (εκφράσεις παρακολούθησης). Τα breakpoints είναι σημεία στον κώδικα στα οποία επιθυμούμε να σταματήσει προσωρινά η εκτέλεση και είναι χρήσιμα έτσι ώστε να βρεθούμε γρήγορα στις εντολές του προγράμματος που παρουσιάζουν ενδιαφέρον. Θα πρέπει να σημειωθεί ότι υπάρχει η δυνατότητα ένα breakpoint να είναι υπό συνθήκη (conditional breakpoint). Αυτό σημαίνει ότι φθάνοντας η εκτέλεση σε ένα breakpoint υπό συνθήκη, θα σταματήσει προσωρινά η εκτέλεση του προγράμματος μόνο στη περίπτωση που η συνθήκη θα είναι αληθής. Από την άλλη μεριά, τα watches είναι εκφράσεις που είναι επιθυμητό να παρακολουθούνται κατά την εκτέλεση του προγράμματος. Αν μια έκφραση που παρακολουθείται αλλάξει, τότε η εκτέλεση του κώδικα θα κάνει παύση στην εντολή που προκαλεί αυτή την αλλαγή και θα εκτυπωθεί η παλιά και η νέα τιμή της έκφρασης.  
Το λογισμικό αποσφαλμάτωσης που θα παρουσιαστεί στη συνέχεια είναι το GDB (GNU Debugger), το οποίο είναι ένα λογισμικό που λειτουργεί σε περιβάλλον γραμμής εντολών. Συνήθως συμπεριλαμβάνεται στην εγκατάσταση του μεταγλωττιστή της C και εγκαθίσταται μαζί με αυτόν. Για να μπορεί να γίνει χρήση του GDB και να εμφανίζονται τα ονόματα αναγνωριστικών (π.χ. ονόματα μεταβλητών, ονόματα συναρτήσεων) που χρησιμοποιούνται στον πηγαίο κώδικα, θα πρέπει η μεταγλώττιση να γίνει χρησιμοποιώντας τον διακόπτη <span class="p-style">‐g</span> (που σημαίνει συμπερίληψη συμβόλων αποσφαλμάτωσης). Εναλλακτικά, συχνά χρησιμοποιείται ο διακόπτης <span class="p-style">‐g3</span> που σημαίνει ότι θα εμφανίζονται περισσότερες πληροφορίες αποσφαλμάτωσης, όπως για παράδειγμα είναι οι αναπτύξεις μακροεντολών (macro expansions). Υπάρχουν πολλές ακόμα επιλογές για τον συγκεκριμένο διακόπτη που μπορούν να διερευνηθούν για την περίπτωση του μεταγλωττιστή gcc στο <a href="https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html" target="_blank">https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html</a>  
Οι βασικές εντολές του GDB είναι οι ακόλουθες:

1. <span class="p-style">start</span> - Εκκίνηση της εκτέλεσης του προγράμματος.
2. <span class="p-style">run</span> - Εκτέλεση του προγράμματος μέχρι να συναντήσει ένα breakpoint.
3. <span class="p-style">where</span> - Εμφάνιση της στοίβας κλήσεων (call stack).
4. <span class="p-style">list</span> - Εμφάνιση των γραμμών του πηγαίου κώδικα γύρω από το σημείο εκτέλεσης.
5. <span class="p-style">break &lt;file:line#&gt;</span> - Ορισμός ενός breakpoint στη γραμμή #.
6. <span class="p-style">break &lt;file:line#&gt; if &lt;expression&gt;</span> - Ορισμός ενός breakpoint υπό συνθήκη στη γραμμή #.
7. <span class="p-style">watch &lt;expression&gt;</span> - Ορισμός ενός watch για μια έκφραση.
8. <span class="p-style">continue</span> ή <span class="p-style">c</span> - Συνέχεια εκτέλεσης μέχρι να συναντήσει ένα breakpoint.
9. <span class="p-style">step</span> ή <span class="p-style">s</span> - Μετάβαση στην επόμενη εντολή του κώδικα, είσοδος μέσα στη συνάρτηση αν η επόμενη εντολή είναι κλήση συνάρτησης (step into).
10. <span class="p-style">next</span> ή <span class="p-style">n</span> - Μετάβαση στην επόμενη εντολή του κώδικα, χωρίς την είσοδο μέσα σε συναρτήσεις (step over).
11. <span class="p-style">finish</span> ή <span class="p-style">fin</span> - Επιστροφή από την τρέχουσα συνάρτηση (step out).
12. <span class="p-style">info args</span> - Εκτύπωση των ορισμάτων γραμμής εκτέλεσης.
13. <span class="p-style">info locals</span> - Εκτύπωση των τοπικών μεταβλητών.
14. <span class="p-style">print &lt;expression&gt;</span> ή <span class="p-style">p <expression></span> - Εκτύπωση της τιμής μιας έκφρασης.
15. <span class="p-style">quit</span> - Έξοδος από το περιβάλλον του GDB. 

Υπάρχουν διαθέσιμες πολλές πηγές στις οποίες περιγράφονται αναλυτικά οι δυνατότητες του GDB όπως είναι το “Debugging with GDB: the GNU Source-Level Debugger for GDB” [^3] και το “Beej’s Quick Guide to GDB” [^4].

### 15.4.1 Βασικές δυνατότητες του GDB

Για το πρώτο παράδειγμα με το GDB θα χρησιμοποιηθεί ένα πρόγραμμα που δέχεται κατά την εκτέλεσή του ορίσματα γραμμής εντολών, πραγματοποιεί κλήσεις συναρτήσεων, χρησιμοποιεί πίνακες, δομές και δείκτες. Ο στόχος στη συγκεκριμένη περίπτωση δεν είναι να εντοπιστεί ένα σφάλμα στον κώδικα, αλλά να παρουσιαστούν ορισμένες βασικές δυνατότητες του GDB. Το πρόγραμμα (κώδικας 15.5) δημιουργεί ένα πλήθος από σημεία του καρτεσιανού επιπέδου με τυχαίες συντεταγμένες. Το πλήθος καθορίζεται ως όρισμα γραμμής εντολών κατά την εκτέλεση του προγράμματος. Στη συνέχεια, υπολογίζει και εμφανίζει την Ευκλείδια απόσταση κάθε σημείου από την αρχή των αξόνων (σημείο 0,0).


```{.c title="Κώδικας 15.5: ch15_p5.c - υπολογισμός αποστάσεων τυχαίων σημείων από την αρχή των αξόνων." linenums="1"}
--8<-- "src/ch15_p5.c"
```

Το πρόγραμμα μεταγλωττίζεται με την ακόλουθη εντολή έτσι ώστε να είναι έτοιμο να χρησιμοποιηθεί από το GDB (προσοχή στον διακόπτη <span class="p-style">‐g</span>):

```
gcc ‐g ch15_p5.c ‐o ch15_p5 ‐lm
```

Η ενεργοποίηση του GDB γίνεται ως εξής:

```
$ gdb ./ch15_p5
GNU gdb (Ubuntu 10.2‐0ubuntu1~20.04~1) 10.2
Copyright (C) 2021 Free Software Foundation , Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY , to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64‐linux‐gnu".
Type "show configuration" for configuration details.
For bug reporting instructions , please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.  

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./ch15_p5...
```

Η εκτέλεση του προγράμματος με παράμετρο την τιμή 5 γίνεται με την εντολή <span class="p-style">start</span> η οποία αυτόματα τοποθετεί ένα breakpoint στην αρχή της <span class="p-style">main()</span>. Εναλλακτικά, η εντολή <span class="p-style">run</span> θα εκτελούσε το πρόγραμμα μέχρι το τέλος του προγράμματος.

```
(gdb) start 5
Temporary breakpoint 1 at 0x1443: file ch15_p5.c, line 29.
Starting program: /.../src/ch15_p5 5

Temporary breakpoint 1, main (argc=2, argv=0x7fffffffd878) at ch15_p5.c:29
29      int main(int argc, char *argv[]) {
```

Η εντολή <span class="p-style">info</span> args παρουσιάζει τις τιμές των ορισμάτων γραμμής εντολών (command line arguments) όπως έχουν εισαχθεί από τον χρήστη. Ειδικότερα, εμφανίζεται το πλήθος των ορισμάτων γραμμής εκτέλεσης (<span class="p-style">argc</span>) και η διεύθυνση του πίνακα χαρακτήρων που περιέχει τα επιμέρους ορίσματα (<span class="p-style">argv</span>). Για να φανούν τα περιεχόμενα του πίνακα <span class="p-style">argv</span> μπορεί να χρησιμοποιηθεί η εντολή <span class="p-style">print</span> σε συνδυασμό με το σύμβολο @ όπως στο παράδειγμα που ακολουθεί. Το <span class="p-style">*argv@2</span> σημαίνει ότι θέλουμε να δούμε τα περιεχόμενα του πίνακα <span class="p-style">argv</span> από την αρχή και μέχρι πριν τη θέση 2.

```
(gdb) info args
argc = 2
argv = 0x7fffffffd878
(gdb) print *argv@2
$1 = {0x7fffffffdb03 "/../src/ch15_p5", 0x7fffffffdb2f "5"}
```

Η εντολή <span class="p-style">next</span> εκτελεί τις εντολές της <span class="p-style">main()</span>, τη μια μετά την άλλη. Φθάνοντας στη γραμμή 37 του κώδικα, μπορούμε να δούμε τις τρέχουσες τιμές των τοπικών μεταβλητών με την εντολή <span class="p-style">info locals</span>. Στη συνέχεια μεταβαίνουμε μέσα στη συνάρτηση <span class="p-style">fill_vector()</span> με την εντολή <span class="p-style">step</span>.

```
(gdb) next
30        if (argc != 2) {
(gdb) next
34        const int N = atoi(argv[1]);
(gdb) next
35        struct point *points[N];
(gdb) next
36        struct point origin = {0.0, 0.0};
(gdb) next
37        fill_vector(points, N);
(gdb) info locals
N = 5
points = {0x7fffffffd870 , 0x0, 0x0, 0x7ffff7cbf5c4 <__GI_atoi+20>, 0x0}
origin = {x = 0, y = 0}
(gdb) step
fill_vector (points=0x7fffffffd6c0 , N=5) at ch15_p5.c:21
21        srand(1234); // use seed for getting reproducible results
```

Ακολουθεί η εκτέλεση των εντολών της <span class="p-style">fill_vector()</span> με την εντολή <span class="p-style">next</span> και μέχρι να συναντήσουμε την πρώτη κλήση της συνάρτησης <span class="p-style">randfrom()</span>, οπότε και δίνεται ξανά η εντολή <span class="p-style">step</span> για τη μετάβαση εντός της <span class="p-style">randfrom()</span>. Η εντολή where δείχνει τη στοίβα χρόνου εκτέλεσης στην κορυφή της οποίας βρίσκεται η συνάρτηση <span class="p-style">randfrom()</span>, κάτω από αυτή η <span class="p-style">fill_vector()</span> και κάτω από αυτή η <span class="p-style">main()</span>. Με την εντολή <span class="p-style">fin</span> πραγματοποιείται εκτέλεση των υπόλοιπων εντολών της τρέχουσας ενεργής συνάρτησης, δηλαδή της <span class="p-style">randfrom()</span>, ενώ αν δοθεί και δεύτερη φορά η εντολή <span class="p-style">fin</span>, ολοκληρώνεται και η εκτέλεση της συνάρτησης <span class="p-style">fill_vector()</span>.

```
(gdb) next
22          for (int i = 0; i < N; i++) {
(gdb) next
23          points[i] = malloc(sizeof(struct point));
(gdb) next
24          points[i]‐>x = randfrom(‐100, 100);
(gdb) step
randfrom (min=‐100, max=100) at ch15_p5.c:15
15          double range = (max ‐ min);
(gdb) where
#0 randfrom (min=‐100, max=100) at ch15_p5.c:15
#1 0x00005555555553c4 in fill_vector (points=0x7fffffffd6c0 , N=5) at ch15_p5.c:24
#2 0x000055555555557f in main (argc=2, argv=0x7fffffffd878) at ch15_p5.c:37
(gdb) fin
Run till exit from #0 randfrom (min=‐100, max=100) at ch15_p5.c:15
0x00005555555553c4 in fill_vector (points=0x7fffffffd6c0 , N=5) at ch15_p5.c:24
24          points[i]‐>x = randfrom(‐100, 100);
Value returned is $2 = ‐55.376385317824955
(gdb) fin
Run till exit from #0 0x00005555555553c4 in fill_vector (points=0x7fffffffd6c0 , N=5)
    ↪ at ch15_p5.c:24
main (argc=2, argv=0x7fffffffd878) at ch15_p5.c:38
38          for (int i = 0; i < N; i++) {
```

Μπορούμε να δούμε τις τιμές των μεταβλητών με τη χρήση της <span class="p-style">print</span> όπως στη συνέχεια. Συνεχίζουμε την εκτέλεση του κώδικα με την εντολή <span class="p-style">next</span> και «μπαίνουμε» με την εντολή <span class="p-style">step</span> μέσα στη συνάρτηση <span class="p-style">distance()</span>. Ολοκληρώνουμε την εκτέλεση της <span class="p-style">distance()</span> με την εντολή <span class="p-style">fin</span>.

```
(gdb) print points
$3 = {0x5555555592a0 , 0x5555555592c0 , 0x5555555592e0 , 0x555555559300 , 0x555555559320}
(gdb) print points[0]
$4 = (struct point *) 0x5555555592a0
(gdb) print *points[0]
$5 = {x = ‐55.376385317824955, y = ‐56.640755830631008}
(gdb) next
39          double d = distance(points[i], &origin);
(gdb) step
distance (p1=0x5555555592a0 , p2=0x7fffffffd730) at ch15_p5.c:11
11          return sqrt(pow(p1‐>x ‐ p2‐>x, 2) + pow(p1‐>y ‐ p2‐>y, 2));
(gdb) fin
Run till exit from #0 distance (p1=0x5555555592a0 , p2=0x7fffffffd730) at ch15_p5.c:11
0x00005555555555a5 in main (argc=2, argv=0x7fffffffd878) at ch15_p5.c:39
39          double d = distance(points[i], &origin);
Value returned is $6 = 79.21312562911136
```

Η εντολή for στη <span class="p-style">main()</span> στη γραμμή 38 θα εκτελεστεί για 4 ακόμα φορές. Για να σταματήσουμε την εκτέλεση στην αρχή της τελευταίας επανάληψης χρησιμοποιούμε την εντολή <span class="p-style">break</span> ορίζοντας τη συνθήκη <span class="p-style">i==4</span> και συνεχίζουμε την εκτέλεση μέχρι το breakpoint με την εντολή <span class="p-style">continue</span>. Η εντολή <span class="p-style">info locals</span> δείχνει ότι πράγματι η εκτέλεση έχει κάνει παύση όταν η μεταβλητή <span class="p-style">i</span> έχει λάβει την τιμή 4.

```
(gdb) break 40 if i == 4
Breakpoint 2 at 0x5555555555bc: file ch15_p5.c, line 40.
(gdb) continue
Continuing.
point0=(‐55.38,‐56.64) distance from origin= 79.21
point1=(‐10.49,‐01.48) distance from origin= 10.59
point2=(+13.87,‐05.24) distance from origin= 14.83
point3=(‐05.02,‐93.27) distance from origin= 93.40

Breakpoint 2, main (argc=2, argv=0x7fffffffd878) at ch15_p5.c:40
40          printf("point%d=(%+06.2f,%+06.2f) distance from origin=%6.2f\n", i,
(gdb) info locals
d = 129.0546641270152
i = 4
N = 5
points = {0x5555555592a0 , 0x5555555592c0 , 0x5555555592e0 , 0x555555559300 ,
    ↪ 0x555555559320}
origin = {x = 0, y = 0}
```

Η εκτέλεση του κώδικα ολοκληρώνεται με την εντολή <span class="p-style">continue</span>. Η έξοδος από το GDB γίνεται με την εντολή <span class="p-style">quit</span>.

```
(gdb) continue
Continuing.
point4=(+90.81,+91.70) distance from origin=129.05
[Inferior 1 (process 3515) exited normally]
(gdb) quit
```

Αξίζει να σημειωθεί ότι υπάρχει η δυνατότητα να εμφανιστεί ένα «φιλικότερο περιβάλλον» για το GDB με τη χρήση διαφόρων front-ends. Ένα παράδειγμα φαίνεται στο Σχήμα 15.1 όπου το GDB ενεργοποιείται με τον διακόπτη ‐tui. Άλλα front-ends που μπορούν να χρησιμοποιηθούν είναι το cgdb(1) και το gdbgui (2). Επίσης, επεξεργαστές κειμένου όπως το Visual Studio Code και το vim μπορούν να συνδεθούν με το GDB.
{ .annotate }

1. <a href="http://cgdb.github.io/" target="_blank">http://cgdb.github.io/</a>
2. <a href="https://www.gdbgui.com/" target="_blank">https://www.gdbgui.com/</a>


```
$ gdb ‐tui ./ch15_p5
```

![ch15_p5.png](src/images/ch15_p5-tui-cropped-brushed.png)

<div style="text-align: center;"><b> Σχήμα 15.1: </b><i>TUI (Text User Interface) για το GDB, ενεργοποίηση με τον διακόπτη -tui</i></div>

### 15.4.2 Ένα μη αναμενόμενο αποτέλεσμα 

Στο ακόλουθο πρόγραμμα (κώδικας 15.6) πραγματοποιείται κλήση δύο σχεδόν όμοιων συναρτήσεων, της <span class="p-style">fun1()</span> και της <span class="p-style">fun2()</span>. Παρατηρείται η εξής «περίεργη» συμπεριφορά: εμφανίζονται τα αποτελέσματα 5 και 10, με το δεύτερο από αυτά να μην φαίνεται να δικαιολογείται από τον κώδικα. Πραγματοποιώντας αποσφαλμάτωση εντοπίζεται ο λόγος εμφάνισης των συγκεκριμένων αποτελεσμάτων.

```{.c title="Κώδικας 15.6: ch15_p6.c - δύο σχεδόν ίδιες συναρτήσεις, με διαφορετική όμως συμπεριφορά." linenums="1"}
--8<-- "src/ch15_p6.c"
```

Η μεταγλώττιση του κώδικα γίνεται με την ακόλουθη εντολή:

```
$ gcc ‐g ch15_p6.c ‐o ch15_p6
```

Ακολουθούμε τα επόμενα βήματα καλώντας το gdb.

```
$ gdb ch15_p6
GNU gdb (Ubuntu 10.2‐0ubuntu1~20.04~1) 10.2
...
Type "apropos word" to search for commands related to "word"...
Reading symbols from ch15_p6...
(gdb) start
Temporary breakpoint 1 at 0x1188: file ch15_p6.c, line 18.
Starting program: /.../src/ch15_p6

Temporary breakpoint 1, main () at ch15_p6.c:18
18          z1 = fun1(5);
(gdb) step
fun1 (a=5) at ch15_p6.c:5
5           int x = 0;
(gdb) next
6           x += a;
(gdb) next
7           return x;
(gdb) print x
$1 = 5
(gdb) print &x
$2 = (int *) 0x7fffffffd75c
(gdb) fin
Run till exit from #0 fun1 (a=5) at ch15_p6.c:7
0x0000555555555192 in main () at ch15_p6.c:18
18          z1 = fun1(5);
Value returned is $3 = 5
(gdb) next
19          z2 = fun2(5);
(gdb) step
fun2 (b=5) at ch15_p6.c:12
12          y += b;
(gdb) next
13          return y;
(gdb) print y
$4 = 10
(gdb) print &y
$5 = (int *) 0x7fffffffd75c
(gdb) fin
Run till exit from #0 fun2 (b=5) at ch15_p6.c:13
0x000055555555519f in main () at ch15_p6.c:19
19          z2 = fun2(5);
Value returned is $6 = 10
(gdb) continue
Continuing.
5
10
[Inferior 1 (process 3615) exited normally]
(gdb) quit
```

Διαπιστώνουμε ότι η μεταβλητή <span class="p-style">x</span> στη συνάρτηση <span class="p-style">fun1</span> και η μεταβλητή <span class="p-style">y</span> στη συνάρτηση <span class="p-style">fun2()</span> μοιράζονται την ίδια θέση μνήμης (τη θέση μνήμης <span class="p-style">0x7fffffffd75c</span> στη συγκεκριμένη εκτέλεση του προγράμματος). Εφόσον πρώτα εκτελείται η συνάρτηση <span class="p-style">fun1()</span>, αφήνει στη θέση μνήμης που βρίσκεται η μεταβλητή <span class="p-style">x</span> την τιμή 5, η οποία χρησιμοποιείται ως αρχική τιμή στη συνέχεια για τη μεταβλητή <span class="p-style">y</span> από τη συνάρτηση <span class="p-style">fun2()</span>. Η συμπεριφορά αυτή έχει να κάνει με τον τρόπο με τον οποίο καλούνται οι συναρτήσεις κάνοντας χρήση της στοίβας χρόνου εκτέλεσης. Όταν από τη <span class="p-style">main()</span> κλήθηκε η συνάρτηση <span class="p-style">fun1()</span> δημιουργήθηκε στην κορυφή της στοίβας, πάνω από τον χώρο που καταλάμβανε το πλαίσιο στοίβας (stack frame) της <span class="p-style">main()</span>, ένα νέο πλαίσιο στοίβας για τη συνάρτηση <span class="p-style">fun1()</span>. Το πλαίσιο στοίβας της <span class="p-style">fun1()</span> έγινε το ενεργό πλαίσιο στοίβας και δεσμεύθηκε σε αυτό χώρος μνήμης για τις τοπικές μεταβλητές της <span class="p-style">fun1()</span> (την <span class="p-style">a</span>, την <span class="p-style">x</span> και την τιμή επιστροφής της συνάρτησης). Όταν ολοκληρώθηκε η εκτέλεση της <span class="p-style">fun1()</span>, η θέση του ενεργού πλαισίου στοίβας ενημερώθηκε έτσι ώστε να δείχνει ξανά τη <span class="p-style">main()</span>, αλλά τα περιεχόμενα του πλαισίου στοίβας της <span class="p-style">fun1()</span> δεν άλλαξαν. Αμέσως μετά κλήθηκε η συνάρτηση <span class="p-style">fun2()</span>, που έχει το ίδιο πλήθος και είδος τοπικών μεταβλητών και μάλιστα με την ίδια σειρά με την <span class="p-style">fun1()</span>. Οπότε, στο πλαίσιο στοίβας που δημιουργήθηκε για τη <span class="p-style">fun2()</span> η μεταβλητή της <span class="p-style">y</span> είχε την ίδια θέση με τη θέση που είχε η μεταβλητή <span class="p-style">x</span> της <span class="p-style">fun1()</span>. Καθώς τα δεδομένα της συγκεκριμένης θέσης δεν έχουν αλλάξει ανάμεσα στις δύο κλήσεις των συναρτήσεων η <span class="p-style">fun2()</span> χρησιμοποιεί ως αρχική τιμή την τιμή που έχει αφήσει εκεί η συνάρτηση <span class="p-style">fun1()</span>. Αυτός είναι και ο λόγος για την «περίεργη συμπεριφορά», η οποία εν τέλει οφείλεται στο ότι στη συνάρτηση <span class="p-style">fun2()</span> δεν γίνεται αρχικοποίηση της μεταβλητής <span class="p-style">y</span> πριν χρησιμοποιηθεί.

### 15.4.3 Εκτός ορίων

Στο ακόλουθο παράδειγμα (κώδικας 15.7) πραγματοποιείται υπολογισμός του αθροίσματος των στοιχείων ενός πίνακα 4 θέσεων που περιέχει την αριθμητική τιμή 1 σε όλα τα στοιχεία του. Ωστόσο, το αποτέλεσμα που προκύπτει είναι 1003 αντί για το αναμενόμενο 4. Αν και είναι σχετικά εύκολο να εντοπίσει κανείς τον λόγο του λανθασμένου αποτελέσματος, το GDB θα μας βοηθήσει να κατανοήσουμε τον λόγο για τον οποίο εμφανίζεται το συγκεκριμένο αποτέλεσμα.

```{.c title="Κώδικας 15.7: ch15_p7.c - κώδικας που παράγει «μη αναμενόμενο» αποτέλεσμα, 1003 έναντι 4." linenums="1"}
--8<-- "src/ch15_p7.c"
```

Η μεταγλώττιση του κώδικα γίνεται με την ακόλουθη εντολή:

```
$ gcc ‐g ch15_p7.c ‐o ch15_p7
```

Ακολουθούμε τα επόμενα βήματα καλώντας το GDB:

```
$ gdb ./ch15_p7
GNU gdb (Ubuntu 10.2‐0ubuntu1~20.04~1) 10.2
...
Reading symbols from ./ch15_p7...
(gdb) start
Temporary breakpoint 1 at 0x1175: file ch15_p7.c, line 3.
Starting program: /.../src/ch15_p7

Temporary breakpoint 1, main () at ch15_p7.c:3
3           int main() {
(gdb) break 10
Breakpoint 2 at 0x5555555551e2: file ch15_p7.c, line 10.
(gdb) continue
Continuing.
Breakpoint 2, main () at ch15_p7.c:10
10          printf("%d \n", sum);
(gdb) info locals
sum = 1003
a = {1, 1, 1, 1}
dummy = {999, 999, 999, 999}
(gdb) print &a[4]
$1 = (int *) 0x7fffffffd760
(gdb) print &dummy[0]
$2 = (int *) 0x7fffffffd760
(gdb) continue
Continuing.
1003
[Inferior 1 (process 24779) exited normally]
(gdb) quit
```

Το πρόβλημα έχει να κάνει με το ότι η εντολή <span class="p-style">for</span> πραγματοποιεί πρόσβαση εκτός των ορίων του πίνακα <span class="p-style">a</span>, λόγω του ότι χρησιμοποιείται ο τελεστής <span class="p-style">&lt;=</span> αντί για τον τελεστή <span class="p-style">&lt;</span> σε συνδυασμό με το μέγεθος του πίνακα που είναι <span class="p-style">4</span>. Στη μνήμη αμέσως μετά από τον χώρο που καταλαμβάνει ο πίνακας <span class="p-style">a</span>, ακολουθεί ο χώρος που καταλαμβάνει ο πίνακας <span class="p-style">dummy</span>. Άρα η διεύθυνση μνήμης στην οποία βρίσκεται το πρώτο στοιχείο του πίνακα <span class="p-style">dummy</span>, δηλαδή το <span class="p-style">dummy[0]</span>, είναι η ίδια με τη διεύθυνση μνήμης ξεκινώντας από την αρχή του πίνακα <span class="p-style">a</span> και μεταβαίνοντας 5 φορές κατά 4 bytes μπροστά. Την πληροφορία αυτή την αποκαλύπτει ο GDB, που δείχνει ότι η διεύθυνση μνήμης του στοιχείου <span class="p-style">a[4]</span> και του στοιχείου <span class="p-style">dummy[0]</span> είναι οι ίδιες (<span class="p-style">0x7fffffffd760</span> σε αυτήν την εκτέλεση του προγράμματος). Συνεπώς, στο άθροισμα των 4 μονάδων του πίνακα <span class="p-style">a</span>, προστίθεται και η τιμή του πρώτου στοιχείου του πίνακα <span class="p-style">dummy</span> που είναι 999 και προκύπτει το άθροισμα 1003 το οποίο και εμφανίζεται.

## 15.5 Ασκήσεις

***Άσκηση 1***  
Δίνεται ο κώδικας 15.8 που αποτελεί μια απόπειρα κώδικα αντιμετάθεσης δύο ακέραιων τιμών. Ωστόσο, δεν έχει ορθή συμπεριφορά. Χρησιμοποιώντας το <span class="p-style">GDB</span> εντοπίστε τον λόγο για τον οποίο δεν πραγματοποιείται σωστά η αντιμετάθεση. Διορθώστε τον κώδικα έτσι ώστε να επιτυγχάνει αντιμετάθεση.

```{.c title="Κώδικας 15.8: ch15_e1.c - συνάρτηση που πραγματοποιεί λανθασμένη αντιμετάθεση ακέραιων μεταβλητών." linenums="1"}
--8<-- "src/ch15_e1.c"
```

??? tip "Λύση άσκησης 1"
    ```{.c linenums="1"}
    --8<-- "\src\"
    ``` 


***Άσκηση 2***  
Το πρόγραμμα του κώδικα 15.9 ζητά από τον χρήστη να εισάγει έναν ακέραιο αριθμό. Ωστόσο, όταν ο χρήστης εισάγει μια ακέραια τιμή, προκύπτει σφάλμα κατάτμησης (segmentation fault). Χρησιμοποιήστε το GDB για να εντοπίσετε το σφάλμα στον κώδικα.

```{.c title="Κώδικας 15.9: ch15_e2.c - λανθασμένος τρόπος εισόδου τιμής από τον χρήστη." linenums="1"}
--8<-- "src/ch15_e2.c"
```

***Άσκηση 3***  
Το πρόγραμμα του κώδικα 15.10 αρχικοποιεί στο μηδέν τα στοιχεία ενός πίνακα ακεραίων. Ωστόσο, κατά την εκτέλεσή του προκύπτει σφάλμα κατάτμησης. Χρησιμοποιήστε το GDB για να εντοπίσετε το σφάλμα στον κώδικα.

```{.c title="Κώδικας 15.10: ch15_e3.c - αρχικοποίηση πίνακα που προκαλεί σφάλμα κατάτμησης." linenums="1"}
--8<-- "src/ch15_e3.c"
```

***Άσκηση 4***  
Δίνεται ο κώδικας 15.11. Ο σκοπός του είναι να χρησιμοποιηθεί ο δείκτης <span class="p-style">ptr</span> για να εμφανίσει το πρώτο στοιχείο του πίνακα, μετά ο δείκτης να αυξηθεί κατά ένα (αριθμητική δεικτών) και να χρησιμοποιηθεί για να εμφανίσει το δεύτερο στοιχείο του πίνακα.

```{.c title="Κώδικας 15.11: ch15_e4.c - κώδικας με «μη αναμενόμενη συμπεριφορά», που παράγει warning αν χρησιμοποιηθεί ο διακόπτης -pedantic." linenums="1"}
--8<-- "src/ch15_e4.c"
```

Ωστόσο, τα αποτελέσματα εκτέλεσης δεν είναι τα αναμενόμενα, και επιπλέον, αν χρησιμοποιηθεί ο διακόπτης μεταγλώττισης <span class="p-style">‐pedantic</span>, τότε εμφανίζεται ένα μήνυμα παρόμοιο με το ακόλουθο:

```
ch15_e4.c:8:13: warning: arithmetic on a pointer to void is a GNU extension
    ↪ [‐Wgnu‐pointer ‐arith]
  ptr = ptr + 1;
        ~~~ ^
```

Εντοπίστε με το GDB την πηγή του προβλήματος.



[^1]: Devon H O’Dell. “The Debugging Mindset: Understanding the psychology of learning strategies leads to effective problem-solving skills.” Στο: <i>Queue</i> 15.1 (2017), σσ. 71–90.  

[^2]: Julia Evans.<i> A debugging manifesto (zine)</i>. <a href="https://jvns.ca/blog/2022/12/08/a-debugging-manifesto/" target="_blank">https://jvns.ca/blog/2022/12/08/a-debugging-manifesto/</a>. [Online; accessed 2022-May-05].  

[^3]: <i>Debugging with GDB: the GNU Source-Level Debugger for GDB (GDB) Version 12.1.90.20221123git.</i> <a href="https://sourceware.org/gdb/onlinedocs/gdb/" target="_blank">https://sourceware.org/gdb/onlinedocs/gdb/</a>. [Online; accessed 2022-May- 05].  

[^4]: <i>Beej’s Quick Guide to GDB - Release 2 (2009 Jun 14)</i>. <a href="https://beej.us/guide/bggdb/" target="_blank">https://beej.us/guide/bggdb/</a>. [Online; accessed 2022-May-05].