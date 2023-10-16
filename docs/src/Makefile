CPPCHECK_OPTIONS=--quiet --enable=all --suppress=missingIncludeSystem

check:
	# Κεφάλαιο 1: Η γλώσσα C – η τρέχουσα κατάσταση 
	cppcheck $(CPPCHECK_OPTIONS) ch1_p1.c
	# Κεφάλαιο 12: Ο προεπεξεργαστής
	cppcheck $(CPPCHECK_OPTIONS) ch12_p1.c ch12_p1.h ch12_p3.c ch12_p4.c ch12_p5.c ch12_p5b.c ch12_p6.c ch12_p7.c ch12_p8.c ch12_p9.c ch12_p11.c ch12_p12.c ch12_p13.c ch12_p14.c
	cppcheck $(CPPCHECK_OPTIONS) ch12_e1.c ch12_e2.c ch12_e3.c ch12_e4.c
	cppcheck $(CPPCHECK_OPTIONS) ch12_p3b.c
    # cppcheck $(CPPCHECK_OPTIONS) ch12_p2.c
	cppcheck $(CPPCHECK_OPTIONS) ch12_p10_main.c ch12_p10_utility.c ch12_p10_utility.h
	# Κεφάλαιο 13: Διαμέριση κώδικα
	cppcheck $(CPPCHECK_OPTIONS) ch13_p1_utility.c ch13_p1_utility.h ch13_p1_io.c ch13_p1_io.h ch13_p1_main.c
	cppcheck $(CPPCHECK_OPTIONS) ch13_p2_geo.c ch13_p2_geom.h ch13_p2_main.c