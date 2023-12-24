#include "tinyfiledialogs.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  int mbox_response;
  char const *ibox_response;
  char const *lTheSaveFileName;
  FILE *lIn;
  char lBuffer[1024];

  /*ορίσματα της tinyfd_messageBox: α) τίτλος παραθύρου διαλόγου, β) μήνυμα
   * παραθύρου διαλόγου, γ) τύπος παραθύρου διαλόγου ("ok" "okcancel" "yesno"
   * "yesnocancel"), δ) τύπος εικονιδίου ("info" "warning" "error" "question"),
   * ε) αριθμός προκαθορισμένου πλήκτρου (0 για cancel/no, 1 για ok/yes,  2 για
   * no στο yesnocancel)*/
  mbox_response = tinyfd_messageBox("Question", "Do you want to continue?",
                                    "yesno", "question", 0);
  if (mbox_response == 0) {
    tinyfd_beep();
    /*ορίσματα της tinyfd_notifyPopoup: α) τίτλος παραθύρου διαλόγου, β) μήνυμα
     * παραθύρου διαλόγου, γ) τύπος εικονιδίου ("info" "warning" "error")*/
    tinyfd_notifyPopup("Bye", "The program was terminated!", "info");
    return 0;
  }

  /*ορίσματα της tinyfd_inputBox: α) τίτλος παραθύρου διαλόγου, β) μήνυμα
   * παραθύρου διαλόγου, γ) προκαθορισμένη είσοδος */
  ibox_response =
      tinyfd_inputBox("An important question",
                      "What is the best age to start learning C?", "0");
  if (ibox_response == 0) {
    tinyfd_beep();
    tinyfd_notifyPopup("Bye", "The program was terminated!", "info");
    return 0;
  }

  /*ορίσματα της tinyfd_saveFileDialog: α) τίτλος παραθύρου διαλόγου, β)
   * προκαθορισμένη διαδρομή και όνομα αρχείου, γ) πλήθος προτύπων αρχείων ή 0,
   * δ) πρότυπα αρχείων π.χ. {"*.txt","*.doc"} ή NULL αν το προηγούμενο όρισμα
   * είναι 0, ε) "text files" για αρχεία κειμένου ή NULL*/
  lTheSaveFileName = tinyfd_saveFileDialog(
      "Your answer deserves to be saved in the filesystem!", "./answer.txt", 0,
      NULL, "text files");
  if (!lTheSaveFileName) {
    tinyfd_messageBox("Error", "Save file name is NULL", "ok", "error", 1);
    return 1;
  }
  lIn = fopen(lTheSaveFileName, "w");
  if (!lIn) {
    tinyfd_messageBox("Error", "Can not open this file in write mode", "ok",
                      "error", 1);
    return 1;
  }
  sprintf(lBuffer, "The best age to start learning C is %s!", ibox_response);
  fputs(lBuffer, lIn);
  fclose(lIn);
  return 0;
}
