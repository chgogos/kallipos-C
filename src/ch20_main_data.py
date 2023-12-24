from random import randrange, seed

UB = 10000  # ανώτατο όριο τυχαίων αριθμών
seed(1729)  # ορίζουμε ως seed μια σταθερή τιμή για επαναληψιμότητα
raw_data = [
    ("daredevil", "12345", randrange(UB)),
    ("happyhippo", "password", randrange(UB)),
    (
        "nerdalert",
        "qwerty",
        randrange(UB),
    ),
]
