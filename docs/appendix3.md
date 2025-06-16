# Γ. Λήψη πληροφοριών για το σύστημα και το μεταγλωττιστή

Το ακόλουθο πρόγραμμα (κώδικας Γ.1) ανιχνεύει τον τύπο του μεταγλωττιστή της C, εμφανίζοντας την έκδοσή του σε περίπτωση που είναι ένας από τους GCC, Clang ή MSVC (Microsoft Visual C++ Compiler). Επιπλέον, εμφανίζει αν το σύστημα έχει αρχιτεκτονική 16, 32 ή 64 bits και τα μεγέθη που καταλαμβάνουν στη μνήμη μεταβλητές διάφορων τύπων καθώς και το εύρος τιμών που μπορούν να «φιλοξενήσουν».

```{.c title="Κώδικας Γ.1: appendix3/types_sizes_widths.c - ανίχνευση έκδοσης μεταγλωττιστή, τύπου συστήματος και εύρους τύπων δεδομένων." linenums="1"}
--8<-- "src/appendix3/types_sizes_widths.c"
```

Η μεταγλώττιση και εκτέλεση του προγράμματος σε έναν υπολογιστή MacOS, με εγκατεστημένο τον μεταγλωττιστή Clang στην έκδοση 15.0.0, θα δώσει την ακόλουθη έξοδο.

```
% gcc types_sizes_widths.c ‐o types_sizes_widths
% ./types_sizes_widths
clang 15.0.0 detected
Platform: 64 bits
Data Type(Storage Size)         Value Range
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
char (1 byte)                   ‐128 to 127
unsigned char (1 byte)           0 to 255
signed char (1 byte)            ‐128 to 127
int (4 bytes)                   ‐2147483648 to 2147483647
unsigned int (4 bytes)           0 to 4294967295
short (2 bytes)                 ‐32768 to 32767
unsigned short (2 bytes)         0 to 65535
long (8 bytes)                  ‐9223372036854775808 to 9223372036854775807
unsigned long (8 bytes)          0 to 18446744073709551615
long long 8 bytes               ‐9223372036854775808 to 9223372036854775807
unsigned long long (8 bytes)     0 to 18446744073709551615
float (4 bytes)                  1.175494e‐38 to 3.402823e+38
double (8 bytes)                 2.225074e‐308 to 1.797693e+308
long double 8 bytes              2.225074e‐308 to 1.797693e+308
```

<div style="text-align: center;"><i>Αποτελέσματα εκτέλεσης σε MacOS Sonoma 14.0, clang 15.0.0.</i></div>

Στο [^1] περιγράφονται οι λεπτομέρειες υλοποίησης ενός προγράμματος που παράγει μια πλήρη αναφορά των ιδιοτήτων του μεταγλωττιστή και του συστήματος. Μεταγλωττίζοντας και εκτελώντας τον κώδικα enquire.c που μπορεί να μεταφορτωθεί από το <a href="https://homepages.cwi.nl/~steven/enquire.html" target="_blank">https://homepages.cwi.nl/~steven/enquire.html</a> λαμβάνεται πληθώρα πληροφοριών για το σύστημα και τον μεταγλωττιστή που χρησιμοποιείται.

[^1]: Pemberton Steve. <i>The Ergonomics of Software Porting: Automatically Configuring Software to the Runtime Environment.</i> <a href="https://homepages.cwi.nl/~steven/enquire/enquire.html" target="_blank">https://homepages.cwi.nl/~steven/enquire/enquire.html</a>. Accessed: 2023-06-01.
