#include <LinkedListLib.h>
//https://github.com/luisllamasbinaburo/Arduino-LinkedList

class Translator {
    int currentLength = 0;
    LinkedList<int> currentLetter = LinkedList<int>();
    int prevNum;
    char letter[8];
    int curLetterLength = 0;
    String outPut = "";

    public: Translator() {}

    void newData(int DataFromDFT) {
      if (currentLetter.GetSize() == 0 && DataFromDFT == 0) {
        return;
      }
      if (DataFromDFT == 1 && currentLength >= 3) {
        resetLetter();
      }
      if (currentLetter.GetSize() == 0) {
        currentLetter.InsertHead(DataFromDFT);
      } else {
        currentLetter.InsertTail(DataFromDFT);
      }
      if (currentLetter.GetSize() > 1) {
        prevNum = currentLetter.GetAt(currentLetter.GetSize() - 2);
        if (DataFromDFT == 0) {
          if (prevNum == 1) {
            if (currentLength == 1) {
              letter[curLetterLength] = '.';
              curLetterLength++;
              currentLength = 1;
              return;
            }
            if (currentLength == 3) {
              letter[curLetterLength] = '_';
              curLetterLength++;
              currentLength = 1;
              return;
            }
          }
          if (prevNum == 0) {
            currentLength++;
            if (currentLength == 3) {
              outPut = finishLetter();
              Serial.print(outPut);
              curLetterLength++;
              return;
            }
            if (currentLength == 7) {
              outPut = finishWord();
              Serial.print(outPut);
              return;
            }
          }
        } else if (DataFromDFT == 1) {
          if (prevNum == 1) {
            currentLength++;
            return;
          } else if (prevNum == 0) {
            currentLength = 1;
            return;
          }
        }
      } else {
        currentLength = 1;
      }
    }

    void resetLetter() {
      currentLetter.Clear();
      curLetterLength = 0;
      memset(letter, '\0', sizeof(letter));
    }

    char finishWord() {
      resetLetter();
      return ' ';
    }

    char finishLetter() {
      //takes letter[] and searces a switch case from morsecode to ASCII
      switch (letter[0]) {
        case '.'://.
          switch (letter[1]) {
            case '.'://..
              switch (letter[2]) {
                case '.'://...
                  switch (letter[3]) {
                    case '.'://....
                      switch (letter[4]) {
                        case '.'://.....
                          switch (letter[5]) {
                            case '.'://......
                              switch (letter[6]) {
                                case '.'://.......
                                  switch (letter[7]) {
                                    case '.'://........
                                      return '|';
                                      break;
                                    case '_'://.......-
                                      break;
                                    default://.......
                                      break;
                                  }
                                  break;
                                case '_'://......-
                                  switch (letter[7]) {
                                    case '.'://......-.
                                      break;
                                    case '_'://......--
                                      break;
                                    default://......-
                                      break;
                                  }
                                  break;
                                default://.......
                                  break;
                              }
                              break;
                            case '_'://.....-
                              switch (letter[6]) {
                                case '.'://.....-.
                                  switch (letter[7]) {
                                    case '.'://.....-..
                                      break;
                                    case '_'://.....-.-
                                      break;
                                    default://.....-.
                                      break;
                                  }
                                  break;
                                case '_'://......--
                                  switch (letter[7]) {
                                    case '.'://.....--.
                                      break;
                                    case '_'://.....---
                                      break;
                                    default://.....--
                                      break;
                                  }
                                  break;
                                default://.....-
                                  break;
                              }
                              break;
                            default://.....
                              return '5';
                              break;
                          }
                          break;
                        case '_'://....-
                          switch (letter[5]) {
                            case '.'://....-.
                              switch (letter[6]) {
                                case '.'://....-..
                                  switch (letter[7]) {
                                    case '.'://....-...
                                      break;
                                    case '_'://....-..-
                                      break;
                                    default://....-..
                                      break;
                                  }
                                  break;
                                case '_'://....-.-
                                  switch (letter[7]) {
                                    case '.'://....-.-.
                                      break;
                                    case '_'://....-.--
                                      break;
                                    default://....-.-
                                      break;
                                  }
                                  break;
                                default://....-.
                                  break;
                              }
                              break;
                            case '_'://....--
                              switch (letter[6]) {
                                case '.'://....--.
                                  switch (letter[7]) {
                                    case '.'://....--..
                                      break;
                                    case '_'://....--.-
                                      break;
                                    default://....--.
                                      break;
                                  }
                                  break;
                                case '_'://....---
                                  switch (letter[7]) {
                                    case '.'://....---.
                                      break;
                                    case '_'://....----
                                      break;
                                    default://....---
                                      break;
                                  }
                                  break;
                                default://....--
                                  break;
                              }
                              break;
                            default://....-
                              return '4';
                              break;
                          }
                          break;
                        default://....
                          return 'H';
                          break;
                      }
                      break;
                    case '_'://...-
                      switch (letter[4]) {
                        case '.'://...-.
                          switch (letter[5]) {
                            case '.'://...-..
                              switch (letter[6]) {
                                case '.'://...-...
                                  switch (letter[7]) {
                                    case '.'://...-....
                                      break;
                                    case '_'://...-...-
                                      break;
                                    default://...-...
                                      break;
                                  }
                                  break;
                                case '_'://...-..-
                                  switch (letter[7]) {
                                    case '.'://...-..-.
                                      break;
                                    case '_'://...-..--
                                      break;
                                    default://...-..-
                                      return '$';
                                      break;
                                  }
                                  break;
                                default://...-..
                                  break;
                              }
                              break;
                            case '_'://...-.-
                              switch (letter[6]) {
                                case '.'://...-.-.
                                  switch (letter[7]) {
                                    case '.'://...-.-..
                                      break;
                                    case '_'://...-.-.-
                                      break;
                                    default://...-.-.
                                      break;
                                  }
                                  break;
                                case '_'://...-.--
                                  switch (letter[7]) {
                                    case '.'://...-.--.
                                      break;
                                    case '_'://...-.---
                                      break;
                                    default://...-.--
                                      break;
                                  }
                                  break;
                                default://...-.-
                                  break;
                              }
                              break;
                            default://...-.
                              break;
                          }
                          break;
                        case '_'://...--
                          switch (letter[5]) {
                            case '.'://...--.
                              switch (letter[6]) {
                                case '.'://...--..
                                  switch (letter[7]) {
                                    case '.'://...--...
                                      break;
                                    case '_'://...--..-
                                      break;
                                    default://...--..
                                      break;
                                  }
                                  break;
                                case '_'://...--.-
                                  switch (letter[7]) {
                                    case '.'://...--.-.
                                      break;
                                    case '_'://...--.--
                                      break;
                                    default://...--.-
                                      break;
                                  }
                                  break;
                                default://...--.
                                  break;
                              }
                              break;
                            case '_'://...---
                              switch (letter[6]) {
                                case '.'://...---.
                                  switch (letter[7]) {
                                    case '.'://...---..
                                      break;
                                    case '_'://...---.-
                                      break;
                                    default://...---.
                                      break;
                                  }
                                  break;
                                case '_'://...----
                                  switch (letter[7]) {
                                    case '.'://...----.
                                      break;
                                    case '_'://...-----
                                      break;
                                    default://...----
                                      break;
                                  }
                                  break;
                                default://...---
                                  break;
                              }
                              break;
                            default://...--
                              return '3';
                              break;
                          }
                          break;
                        default://...-
                          return 'V';
                          break;
                      }
                    default://...
                      return 'S';
                      break;
                  }
                case '_'://..-
                  switch (letter[3]) {
                    case '.'://..-.
                      switch (letter[4]) {
                        case '.'://..-..
                          switch (letter[5]) {
                            case '.'://..-...
                              switch (letter[6]) {
                                case '.'://..-....
                                  switch (letter[7]) {
                                    case '.'://..-.....
                                      break;
                                    case '_'://..-....-
                                      break;
                                    default://..-....
                                      break;
                                  }
                                  break;
                                case '_'://..-...-
                                  switch (letter[7]) {
                                    case '.'://..-...-.
                                      break;
                                    case '_'://..-...--
                                      break;
                                    default://..-...-
                                      break;
                                  }
                                  break;
                                default://..-...
                                  break;
                              }
                              break;
                            case '_'://..-..-
                              switch (letter[6]) {
                                case '.'://..-..-.
                                  switch (letter[7]) {
                                    case '.'://..-..-..
                                      break;
                                    case '_'://..-..-.-
                                      break;
                                    default://..-..-.
                                      break;
                                  }
                                  break;
                                case '_'://..-..--
                                  switch (letter[7]) {
                                    case '.'://..-..--.
                                      break;
                                    case '_'://..-..---
                                      break;
                                    default://..-..--
                                      break;
                                  }
                                  break;
                                default://..-..-
                                  break;
                              }
                              break;
                            default://..-..
                              return 144;
                              break;
                          }
                          break;
                        case '_'://..-.-
                          switch (letter[5]) {
                            case '.'://..-.-.
                              switch (letter[6]) {
                                case '.'://..-.-..
                                  switch (letter[7]) {
                                    case '.'://..-.-...
                                      break;
                                    case '_'://..-.-..-
                                      break;
                                    default://..-.-..
                                      break;
                                  }
                                  break;
                                case '_'://..-.-.-
                                  switch (letter[7]) {
                                    case '.'://..-.-.-.
                                      break;
                                    case '_'://..-.-.--
                                      break;
                                    default://..-.-.-
                                      break;
                                  }
                                  break;
                                default://..-.-.
                                  break;
                              }
                              break;
                            case '_'://..-.--
                              switch (letter[6]) {
                                case '.'://..-.--.
                                  switch (letter[7]) {
                                    case '.'://..-.--..
                                      break;
                                    case '_'://..-.--.-
                                      break;
                                    default://..-.--.
                                      break;
                                  }
                                  break;
                                case '_'://..-.---
                                  switch (letter[7]) {
                                    case '.'://..-.---.
                                      break;
                                    case '_'://..-.----
                                      break;
                                    default://..-.---
                                      break;
                                  }
                                  break;
                                default://..-.--
                                  break;
                              }
                              break;
                            default://..-.-
                              break;
                          }
                          break;
                        default://..-.
                          return 'F';
                          break;
                      }
                      break;
                    case '_'://..--
                      switch (letter[4]) {
                        case '.'://..--.
                          switch (letter[5]) {
                            case '.'://..--..
                              switch (letter[6]) {
                                case '.'://..--...
                                  switch (letter[7]) {
                                    case '.'://..--....
                                      break;
                                    case '_'://..--...-
                                      break;
                                    default://..--...
                                      break;
                                  }
                                  break;
                                case '_'://..--..-
                                  switch (letter[7]) {
                                    case '.'://..--..-.
                                      break;
                                    case '_'://..--..--
                                      break;
                                    default://..--..-
                                      break;
                                  }
                                  break;
                                default://..--..
                                  return '?';
                                  break;
                              }
                              break;
                            case '_'://..--.-
                              switch (letter[6]) {
                                case '.'://..--.-.
                                  switch (letter[7]) {
                                    case '.'://..--.-..
                                      break;
                                    case '_'://..--.-.-
                                      break;
                                    default://..--.-.
                                      break;
                                  }
                                  break;
                                case '_'://..--.--
                                  switch (letter[7]) {
                                    case '.'://..--.--.
                                      break;
                                    case '_'://..--.---
                                      break;
                                    default://..--.--
                                      break;
                                  }
                                  break;
                                default://..--.-
                                  return '_';
                                  break;
                              }
                              break;
                            default://..--.
                              break;
                          }
                          break;
                        case '_'://..---
                          switch (letter[5]) {
                            case '.'://..---.
                              switch (letter[6]) {
                                case '.'://..---..
                                  switch (letter[7]) {
                                    case '.'://..---...
                                      break;
                                    case '_'://..---..-
                                      break;
                                    default://..---..
                                      break;
                                  }
                                  break;
                                case '_'://..---.-
                                  switch (letter[7]) {
                                    case '.'://..---.-.
                                      break;
                                    case '_'://..---.--
                                      break;
                                    default://..---.-
                                      break;
                                  }
                                  break;
                                default://..---.
                                  break;
                              }
                              break;
                            case '_'://..----
                              switch (letter[6]) {
                                case '.'://..----.
                                  switch (letter[7]) {
                                    case '.'://..----..
                                      break;
                                    case '_'://..----.-
                                      break;
                                    default://..----.
                                      break;
                                  }
                                  break;
                                case '_'://..-----
                                  switch (letter[7]) {
                                    case '.'://..-----.
                                      break;
                                    case '_'://..------
                                      break;
                                    default://..-----
                                      break;
                                  }
                                  break;
                                default://..----
                                  break;
                              }
                              break;
                            default://..---
                              return '2';
                              break;
                          }
                          break;
                        default://..--
                          return 154;
                          break;
                      }
                      break;
                    default://..-
                      return 'U';
                      break;
                  }
                  break;
                default://..
                  return 'I';
                  break;
              }
              break;
            case '_'://.-
              switch (letter[2]) {
                case '.'://.-.
                  switch (letter[3]) {
                    case '.'://.-..
                      switch (letter[4]) {
                        case '.'://.-...
                          switch (letter[5]) {
                            case '.'://.-....
                              switch (letter[6]) {
                                case '.'://.-.....
                                  switch (letter[7]) {
                                    case '.'://.-......
                                      break;
                                    case '_'://.-.....-
                                      break;
                                    default://.-.....
                                      break;
                                  }
                                  break;
                                case '_'://.-....-
                                  switch (letter[7]) {
                                    case '.'://.-....-.
                                      break;
                                    case '_'://.-....--
                                      break;
                                    default://.-....-
                                      break;
                                  }
                                  break;
                                default://.-.....
                                  break;
                              }
                              break;
                            case '_'://.-...-
                              switch (letter[6]) {
                                case '.'://.-...-.
                                  switch (letter[7]) {
                                    case '.'://.-...-..
                                      break;
                                    case '_'://.-...-.-
                                      break;
                                    default://.-...-.
                                      break;
                                  }
                                  break;
                                case '_'://.-....--
                                  switch (letter[7]) {
                                    case '.'://.-...--.
                                      break;
                                    case '_'://.-...---
                                      break;
                                    default://.-...--
                                      break;
                                  }
                                  break;
                                default://.-...-
                                  break;
                              }
                              break;
                            default://.-...
                              return '&';
                              break;
                          }
                          break;
                        case '_'://.-..-
                          switch (letter[5]) {
                            case '.'://.-..-.
                              switch (letter[6]) {
                                case '.'://.-..-..
                                  switch (letter[7]) {
                                    case '.'://.-..-...
                                      break;
                                    case '_'://.-..-..-
                                      break;
                                    default://.-..-..
                                      break;
                                  }
                                  break;
                                case '_'://.-..-.-
                                  switch (letter[7]) {
                                    case '.'://.-..-.-.
                                      break;
                                    case '_'://.-..-.--
                                      break;
                                    default://.-..-.-
                                      break;
                                  }
                                  break;
                                default://.-..-.
                                  return 34;
                                  break;
                              }
                              break;
                            case '_'://.-..--
                              switch (letter[6]) {
                                case '.'://.-..--.
                                  switch (letter[7]) {
                                    case '.'://.-..--..
                                      break;
                                    case '_'://.-..--.-
                                      break;
                                    default://.-..--.
                                      break;
                                  }
                                  break;
                                case '_'://.-..---
                                  switch (letter[7]) {
                                    case '.'://.-..---.
                                      break;
                                    case '_'://.-..----
                                      break;
                                    default://.-..---
                                      break;
                                  }
                                  break;
                                default://.-..--
                                  break;
                              }
                              break;
                            default://.-..-
                              break;
                          }
                          break;
                        default://.-..
                          return 'L';
                          break;
                      }
                      break;
                    case '_'://.-.-
                      switch (letter[4]) {
                        case '.'://.-.-.
                          switch (letter[5]) {
                            case '.'://.-.-..
                              switch (letter[6]) {
                                case '.'://.-.-...
                                  switch (letter[7]) {
                                    case '.'://.-.-....
                                      break;
                                    case '_'://.-.-...-
                                      break;
                                    default://.-.-...
                                      break;
                                  }
                                  break;
                                case '_'://.-.-..-
                                  switch (letter[7]) {
                                    case '.'://.-.-..-.
                                      break;
                                    case '_'://.-.-..--
                                      break;
                                    default://.-.-..-
                                      break;
                                  }
                                  break;
                                default://.-.-..
                                  break;
                              }
                              break;
                            case '_'://.-.-.-
                              switch (letter[6]) {
                                case '.'://.-.-.-.
                                  switch (letter[7]) {
                                    case '.'://.-.-.-..
                                      break;
                                    case '_'://.-.-.-.-
                                      break;
                                    default://.-.-.-.
                                      break;
                                  }
                                  break;
                                case '_'://.-.-.--
                                  switch (letter[7]) {
                                    case '.'://.-.-.--.
                                      break;
                                    case '_'://.-.-.---
                                      break;
                                    default://.-.-.--
                                      break;
                                  }
                                  break;
                                default://.-.-.-
                                  return '.';
                                  break;
                              }
                              break;
                            default://.-.-.
                              return '+';
                              break;
                          }
                          break;
                        case '_'://.-.--
                          switch (letter[5]) {
                            case '.'://.-.--.
                              switch (letter[6]) {
                                case '.'://.-.--..
                                  switch (letter[7]) {
                                    case '.'://.-.--...
                                      break;
                                    case '_'://.-.--..-
                                      break;
                                    default://.-.--..
                                      break;
                                  }
                                  break;
                                case '_'://.-.--.-
                                  switch (letter[7]) {
                                    case '.'://.-.--.-.
                                      break;
                                    case '_'://.-.--.--
                                      break;
                                    default://.-.--.-
                                      break;
                                  }
                                  break;
                                default://.-.--.
                                  break;
                              }
                              break;
                            case '_'://.-.---
                              switch (letter[6]) {
                                case '.'://.-.---.
                                  switch (letter[7]) {
                                    case '.'://.-.---..
                                      break;
                                    case '_'://.-.---.-
                                      break;
                                    default://.-.---.
                                      break;
                                  }
                                  break;
                                case '_'://.-.----
                                  switch (letter[7]) {
                                    case '.'://.-.----.
                                      break;
                                    case '_'://.-.-----
                                      break;
                                    default://.-.----
                                      break;
                                  }
                                  break;
                                default://.-.---
                                  break;
                              }
                              break;
                            default://.-.--
                              break;
                          }
                          break;
                        default://.-.-
                          return 142;
                          break;
                      }
                    default://.-.
                      return 'R';
                      break;
                  }
                case '_'://.--
                  switch (letter[3]) {
                    case '.'://.--.
                      switch (letter[4]) {
                        case '.'://.--..
                          switch (letter[5]) {
                            case '.'://.--...
                              switch (letter[6]) {
                                case '.'://.--....
                                  switch (letter[7]) {
                                    case '.'://.--.....
                                      break;
                                    case '_'://.--....-
                                      break;
                                    default://.--....
                                      break;
                                  }
                                  break;
                                case '_'://.--...-
                                  switch (letter[7]) {
                                    case '.'://.--...-.
                                      break;
                                    case '_'://.--...--
                                      break;
                                    default://.--...-
                                      break;
                                  }
                                  break;
                                default://.--...
                                  break;
                              }
                              break;
                            case '_'://.--..-
                              switch (letter[6]) {
                                case '.'://.--..-.
                                  switch (letter[7]) {
                                    case '.'://.--..-..
                                      break;
                                    case '_'://.--..-.-
                                      break;
                                    default://.--..-.
                                      break;
                                  }
                                  break;
                                case '_'://.--..--
                                  switch (letter[7]) {
                                    case '.'://.--..--.
                                      break;
                                    case '_'://.--..---
                                      break;
                                    default://.--..--
                                      break;
                                  }
                                  break;
                                default://.--..-
                                  break;
                              }
                              break;
                            default://.--..
                              break;
                          }
                          break;
                        case '_'://.--.-
                          switch (letter[5]) {
                            case '.'://.--.-.
                              switch (letter[6]) {
                                case '.'://.--.-..
                                  switch (letter[7]) {
                                    case '.'://.--.-...
                                      break;
                                    case '_'://.--.-..-
                                      break;
                                    default://.--.-..
                                      break;
                                  }
                                  break;
                                case '_'://.--.-.-
                                  switch (letter[7]) {
                                    case '.'://.--.-.-.
                                      break;
                                    case '_'://.--.-.--
                                      break;
                                    default://.--.-.-
                                      break;
                                  }
                                  break;
                                default://.--.-.
                                  return '@';
                                  break;
                              }
                              break;
                            case '_'://.--.--
                              switch (letter[6]) {
                                case '.'://.--.--.
                                  switch (letter[7]) {
                                    case '.'://.--.--..
                                      break;
                                    case '_'://.--.--.-
                                      break;
                                    default://.--.--.
                                      break;
                                  }
                                  break;
                                case '_'://.--.---
                                  switch (letter[7]) {
                                    case '.'://.--.---.
                                      break;
                                    case '_'://.--.----
                                      break;
                                    default://.--.---
                                      break;
                                  }
                                  break;
                                default://.--.--
                                  break;
                              }
                              break;
                            default://.--.-
                              return 181;
                              break;
                          }
                          break;
                        default://.--.
                          return 'P';
                          break;
                      }
                      break;
                    case '_'://.---
                      switch (letter[4]) {
                        case '.'://.---.
                          switch (letter[5]) {
                            case '.'://.---..
                              switch (letter[6]) {
                                case '.'://.---...
                                  switch (letter[7]) {
                                    case '.'://.---....
                                      break;
                                    case '_'://.---...-
                                      break;
                                    default://.---...
                                      break;
                                  }
                                  break;
                                case '_'://.---..-
                                  switch (letter[7]) {
                                    case '.'://.---..-.
                                      break;
                                    case '_'://.---..--
                                      break;
                                    default://.---..-
                                      break;
                                  }
                                  break;
                                default://.---..
                                  break;
                              }
                              break;
                            case '_'://.---.-
                              switch (letter[6]) {
                                case '.'://.---.-.
                                  switch (letter[7]) {
                                    case '.'://.---.-..
                                      break;
                                    case '_'://.---.-.-
                                      break;
                                    default://.---.-.
                                      break;
                                  }
                                  break;
                                case '_'://.---.--
                                  switch (letter[7]) {
                                    case '.'://.---.--.
                                      break;
                                    case '_'://.---.---
                                      break;
                                    default://.---.--
                                      break;
                                  }
                                  break;
                                default://.---.-
                                  break;
                              }
                              break;
                            default://.---.
                              break;
                          }
                          break;
                        case '_'://.----
                          switch (letter[5]) {
                            case '.'://.----.
                              switch (letter[6]) {
                                case '.'://.----..
                                  switch (letter[7]) {
                                    case '.'://.----...
                                      break;
                                    case '_'://.----..-
                                      break;
                                    default://.----..
                                      break;
                                  }
                                  break;
                                case '_'://.----.-
                                  switch (letter[7]) {
                                    case '.'://.----.-.
                                      break;
                                    case '_'://.----.--
                                      break;
                                    default://.----.-
                                      break;
                                  }
                                  break;
                                default://.----.
                                  return 39;
                                  break;
                              }
                              break;
                            case '_'://.-----
                              switch (letter[6]) {
                                case '.'://.-----.
                                  switch (letter[7]) {
                                    case '.'://.-----..
                                      break;
                                    case '_'://.-----.-
                                      break;
                                    default://.-----.
                                      break;
                                  }
                                  break;
                                case '_'://.------
                                  switch (letter[7]) {
                                    case '.'://.------.
                                      break;
                                    case '_'://.-------
                                      break;
                                    default://.------
                                      break;
                                  }
                                  break;
                                default://.-----
                                  break;
                              }
                              break;
                            default://.----
                              return '1';
                              break;
                          }
                          break;
                        default://.---
                          return 'J';
                          break;
                      }
                      break;
                    default://.--
                      return 'W';
                      break;
                  }
                  break;
                default://.-
                  return 'A';
                  break;
              }
              break;
            default://.
              return 'E';
              break;
          }
          break;
        case '_'://-
          switch (letter[1]) {
            case '.'://-.
              switch (letter[2]) {
                case '.'://-..
                  switch (letter[3]) {
                    case '.'://-...
                      switch (letter[4]) {
                        case '.'://-....
                          switch (letter[5]) {
                            case '.'://-.....
                              switch (letter[6]) {
                                case '.'://-......
                                  switch (letter[7]) {
                                    case '.'://-.......
                                      break;
                                    case '_'://-......-
                                      break;
                                    default://-......
                                      break;
                                  }
                                  break;
                                case '_'://-.....-
                                  switch (letter[7]) {
                                    case '.'://-.....-.
                                      break;
                                    case '_'://-.....--
                                      break;
                                    default://-.....-
                                      break;
                                  }
                                  break;
                                default://-......
                                  break;
                              }
                              break;
                            case '_'://-....-
                              switch (letter[6]) {
                                case '.'://-....-.
                                  switch (letter[7]) {
                                    case '.'://-....-..
                                      break;
                                    case '_'://-....-.-
                                      break;
                                    default://-....-.
                                      break;
                                  }
                                  break;
                                case '_'://-.....--
                                  switch (letter[7]) {
                                    case '.'://-....--.
                                      break;
                                    case '_'://-....---
                                      break;
                                    default://-....--
                                      break;
                                  }
                                  break;
                                default://-....-
                                  return '-';
                                  break;
                              }
                              break;
                            default://-....
                              return '6';
                              break;
                          }
                          break;
                        case '_'://-...-
                          switch (letter[5]) {
                            case '.'://-...-.
                              switch (letter[6]) {
                                case '.'://-...-..
                                  switch (letter[7]) {
                                    case '.'://-...-...
                                      break;
                                    case '_'://-...-..-
                                      break;
                                    default://-...-..
                                      break;
                                  }
                                  break;
                                case '_'://-...-.-
                                  switch (letter[7]) {
                                    case '.'://-...-.-.
                                      break;
                                    case '_'://-...-.--
                                      break;
                                    default://-...-.-
                                      break;
                                  }
                                  break;
                                default://-...-.
                                  break;
                              }
                              break;
                            case '_'://-...--
                              switch (letter[6]) {
                                case '.'://-...--.
                                  switch (letter[7]) {
                                    case '.'://-...--..
                                      break;
                                    case '_'://-...--.-
                                      break;
                                    default://-...--.
                                      break;
                                  }
                                  break;
                                case '_'://-...---
                                  switch (letter[7]) {
                                    case '.'://-...---.
                                      break;
                                    case '_'://-...----
                                      break;
                                    default://-...---
                                      break;
                                  }
                                  break;
                                default://-...--
                                  break;
                              }
                              break;
                            default://-...-
                              return '=';
                              break;
                          }
                          break;
                        default://-...
                          return 'B';
                          break;
                      }
                      break;
                    case '_'://-..-
                      switch (letter[4]) {
                        case '.'://-..-.
                          switch (letter[5]) {
                            case '.'://-..-..
                              switch (letter[6]) {
                                case '.'://-..-...
                                  switch (letter[7]) {
                                    case '.'://-..-....
                                      break;
                                    case '_'://-..-...-
                                      break;
                                    default://-..-...
                                      break;
                                  }
                                  break;
                                case '_'://-..-..-
                                  switch (letter[7]) {
                                    case '.'://-..-..-.
                                      break;
                                    case '_'://-..-..--
                                      break;
                                    default://-..-..-
                                      break;
                                  }
                                  break;
                                default://-..-..
                                  break;
                              }
                              break;
                            case '_'://-..-.-
                              switch (letter[6]) {
                                case '.'://-..-.-.
                                  switch (letter[7]) {
                                    case '.'://-..-.-..
                                      break;
                                    case '_'://-..-.-.-
                                      break;
                                    default://-..-.-.
                                      break;
                                  }
                                  break;
                                case '_'://-..-.--
                                  switch (letter[7]) {
                                    case '.'://-..-.--.
                                      break;
                                    case '_'://-..-.---
                                      break;
                                    default://-..-.--
                                      break;
                                  }
                                  break;
                                default://-..-.-
                                  break;
                              }
                              break;
                            default://-..-.
                              return '/';
                              break;
                          }
                          break;
                        case '_'://-..--
                          switch (letter[5]) {
                            case '.'://-..--.
                              switch (letter[6]) {
                                case '.'://-..--..
                                  switch (letter[7]) {
                                    case '.'://-..--...
                                      break;
                                    case '_'://-..--..-
                                      break;
                                    default://-..--..
                                      break;
                                  }
                                  break;
                                case '_'://-..--.-
                                  switch (letter[7]) {
                                    case '.'://-..--.-.
                                      break;
                                    case '_'://-..--.--
                                      break;
                                    default://-..--.-
                                      break;
                                  }
                                  break;
                                default://-..--.
                                  break;
                              }
                              break;
                            case '_'://-..---
                              switch (letter[6]) {
                                case '.'://-..---.
                                  switch (letter[7]) {
                                    case '.'://-..---..
                                      break;
                                    case '_'://-..---.-
                                      break;
                                    default://-..---.
                                      break;
                                  }
                                  break;
                                case '_'://-..----
                                  switch (letter[7]) {
                                    case '.'://-..----.
                                      break;
                                    case '_'://-..-----
                                      break;
                                    default://-..----
                                      break;
                                  }
                                  break;
                                default://-..---
                                  break;
                              }
                              break;
                            default://-..--
                              break;
                          }
                          break;
                        default://-..-
                          return 'X';
                          break;
                      }
                    default://-..
                      return 'D';
                      break;
                  }
                case '_'://-.-
                  switch (letter[3]) {
                    case '.'://-.-.
                      switch (letter[4]) {
                        case '.'://-.-..
                          switch (letter[5]) {
                            case '.'://-.-...
                              switch (letter[6]) {
                                case '.'://-.-....
                                  switch (letter[7]) {
                                    case '.'://-.-.....
                                      break;
                                    case '_'://-.-....-
                                      break;
                                    default://-.-....
                                      break;
                                  }
                                  break;
                                case '_'://-.-...-
                                  switch (letter[7]) {
                                    case '.'://-.-...-.
                                      break;
                                    case '_'://-.-...--
                                      break;
                                    default://-.-...-
                                      break;
                                  }
                                  break;
                                default://-.-...
                                  break;
                              }
                              break;
                            case '_'://-.-..-
                              switch (letter[6]) {
                                case '.'://-.-..-.
                                  switch (letter[7]) {
                                    case '.'://-.-..-..
                                      break;
                                    case '_'://-.-..-.-
                                      break;
                                    default://-.-..-.
                                      break;
                                  }
                                  break;
                                case '_'://-.-..--
                                  switch (letter[7]) {
                                    case '.'://-.-..--.
                                      break;
                                    case '_'://-.-..---
                                      break;
                                    default://-.-..--
                                      break;
                                  }
                                  break;
                                default://-.-..-
                                  break;
                              }
                              break;
                            default://-.-..
                              break;
                          }
                          break;
                        case '_'://-.-.-
                          switch (letter[5]) {
                            case '.'://-.-.-.
                              switch (letter[6]) {
                                case '.'://-.-.-..
                                  switch (letter[7]) {
                                    case '.'://-.-.-...
                                      break;
                                    case '_'://-.-.-..-
                                      break;
                                    default://-.-.-..
                                      break;
                                  }
                                  break;
                                case '_'://-.-.-.-
                                  switch (letter[7]) {
                                    case '.'://-.-.-.-.
                                      break;
                                    case '_'://-.-.-.--
                                      break;
                                    default://-.-.-.-
                                      break;
                                  }
                                  break;
                                default://-.-.-.
                                  break;
                              }
                              break;
                            case '_'://-.-.--
                              switch (letter[6]) {
                                case '.'://-.-.--.
                                  switch (letter[7]) {
                                    case '.'://-.-.--..
                                      break;
                                    case '_'://-.-.--.-
                                      break;
                                    default://-.-.--.
                                      break;
                                  }
                                  break;
                                case '_'://-.-.---
                                  switch (letter[7]) {
                                    case '.'://-.-.---.
                                      break;
                                    case '_'://-.-.----
                                      break;
                                    default://-.-.---
                                      break;
                                  }
                                  break;
                                default://-.-.--
                                  return '!';
                                  break;
                              }
                              break;
                            default://-.-.-
                              return ';';
                              break;
                          }
                          break;
                        default://-.-.
                          return 'C';
                          break;
                      }
                      break;
                    case '_'://-.--
                      switch (letter[4]) {
                        case '.'://-.--.
                          switch (letter[5]) {
                            case '.'://-.--..
                              switch (letter[6]) {
                                case '.'://-.--...
                                  switch (letter[7]) {
                                    case '.'://-.--....
                                      break;
                                    case '_'://-.--...-
                                      break;
                                    default://-.--...
                                      break;
                                  }
                                  break;
                                case '_'://-.--..-
                                  switch (letter[7]) {
                                    case '.'://-.--..-.
                                      break;
                                    case '_'://-.--..--
                                      break;
                                    default://-.--..-
                                      break;
                                  }
                                  break;
                                default://-.--..
                                  break;
                              }
                              break;
                            case '_'://-.--.-
                              switch (letter[6]) {
                                case '.'://-.--.-.
                                  switch (letter[7]) {
                                    case '.'://-.--.-..
                                      break;
                                    case '_'://-.--.-.-
                                      break;
                                    default://-.--.-.
                                      break;
                                  }
                                  break;
                                case '_'://-.--.--
                                  switch (letter[7]) {
                                    case '.'://-.--.--.
                                      break;
                                    case '_'://-.--.---
                                      break;
                                    default://-.--.--
                                      break;
                                  }
                                  break;
                                default://-.--.-
                                  return ')';
                                  break;
                              }
                              break;
                            default://-.--.
                              return '(';
                              break;
                          }
                          break;
                        case '_'://-.---
                          switch (letter[5]) {
                            case '.'://-.---.
                              switch (letter[6]) {
                                case '.'://-.---..
                                  switch (letter[7]) {
                                    case '.'://-.---...
                                      break;
                                    case '_'://-.---..-
                                      break;
                                    default://-.---..
                                      break;
                                  }
                                  break;
                                case '_'://-.---.-
                                  switch (letter[7]) {
                                    case '.'://-.---.-.
                                      break;
                                    case '_'://-.---.--
                                      break;
                                    default://-.---.-
                                      break;
                                  }
                                  break;
                                default://-.---.
                                  break;
                              }
                              break;
                            case '_'://-.----
                              switch (letter[6]) {
                                case '.'://-.----.
                                  switch (letter[7]) {
                                    case '.'://-.----..
                                      break;
                                    case '_'://-.----.-
                                      break;
                                    default://-.----.
                                      break;
                                  }
                                  break;
                                case '_'://-.-----
                                  switch (letter[7]) {
                                    case '.'://-.-----.
                                      break;
                                    case '_'://-.------
                                      break;
                                    default://-.-----
                                      break;
                                  }
                                  break;
                                default://-.----
                                  break;
                              }
                              break;
                            default://-.---
                              break;
                          }
                          break;
                        default://-.--
                          return 'Y';
                          break;
                      }
                      break;
                    default://-.-
                      return 'K';
                      break;
                  }
                  break;
                default://-.
                  return 'N';
                  break;
              }
              break;
            case '_'://--
              switch (letter[2]) {
                case '.'://--.
                  switch (letter[3]) {
                    case '.'://--..
                      switch (letter[4]) {
                        case '.'://--...
                          switch (letter[5]) {
                            case '.'://--....
                              switch (letter[6]) {
                                case '.'://--.....
                                  switch (letter[7]) {
                                    case '.'://--......
                                      break;
                                    case '_'://--.....-
                                      break;
                                    default://--.....
                                      break;
                                  }
                                  break;
                                case '_'://--....-
                                  switch (letter[7]) {
                                    case '.'://--....-.
                                      break;
                                    case '_'://--....--
                                      break;
                                    default://--....-
                                      break;
                                  }
                                  break;
                                default://--.....
                                  break;
                              }
                              break;
                            case '_'://--...-
                              switch (letter[6]) {
                                case '.'://--...-.
                                  switch (letter[7]) {
                                    case '.'://--...-..
                                      break;
                                    case '_'://--...-.-
                                      break;
                                    default://--...-.
                                      break;
                                  }
                                  break;
                                case '_'://--....--
                                  switch (letter[7]) {
                                    case '.'://--...--.
                                      break;
                                    case '_'://--...---
                                      break;
                                    default://--...--
                                      break;
                                  }
                                  break;
                                default://--...-
                                  break;
                              }
                              break;
                            default://--...
                              return '7';
                              break;
                          }
                          break;
                        case '_'://--..-
                          switch (letter[5]) {
                            case '.'://--..-.
                              switch (letter[6]) {
                                case '.'://--..-..
                                  switch (letter[7]) {
                                    case '.'://--..-...
                                      break;
                                    case '_'://--..-..-
                                      break;
                                    default://--..-..
                                      break;
                                  }
                                  break;
                                case '_'://--..-.-
                                  switch (letter[7]) {
                                    case '.'://--..-.-.
                                      break;
                                    case '_'://--..-.--
                                      break;
                                    default://--..-.-
                                      break;
                                  }
                                  break;
                                default://--..-.
                                  break;
                              }
                              break;
                            case '_'://--..--
                              switch (letter[6]) {
                                case '.'://--..--.
                                  switch (letter[7]) {
                                    case '.'://--..--..
                                      break;
                                    case '_'://--..--.-
                                      break;
                                    default://--..--.
                                      break;
                                  }
                                  break;
                                case '_'://--..---
                                  switch (letter[7]) {
                                    case '.'://--..---.
                                      break;
                                    case '_'://--..----
                                      break;
                                    default://--..---
                                      break;
                                  }
                                  break;
                                default://--..--
                                  return ',';
                                  break;
                              }
                              break;
                            default://--..-
                              break;
                          }
                          break;
                        default://--..
                          return 'Z';
                          break;
                      }
                      break;
                    case '_'://--.-
                      switch (letter[4]) {
                        case '.'://--.-.
                          switch (letter[5]) {
                            case '.'://--.-..
                              switch (letter[6]) {
                                case '.'://--.-...
                                  switch (letter[7]) {
                                    case '.'://--.-....
                                      break;
                                    case '_'://--.-...-
                                      break;
                                    default://--.-...
                                      break;
                                  }
                                  break;
                                case '_'://--.-..-
                                  switch (letter[7]) {
                                    case '.'://--.-..-.
                                      break;
                                    case '_'://--.-..--
                                      break;
                                    default://--.-..-
                                      break;
                                  }
                                  break;
                                default://--.-..
                                  break;
                              }
                              break;
                            case '_'://--.-.-
                              switch (letter[6]) {
                                case '.'://--.-.-.
                                  switch (letter[7]) {
                                    case '.'://--.-.-..
                                      break;
                                    case '_'://--.-.-.-
                                      break;
                                    default://--.-.-.
                                      break;
                                  }
                                  break;
                                case '_'://--.-.--
                                  switch (letter[7]) {
                                    case '.'://--.-.--.
                                      break;
                                    case '_'://--.-.---
                                      break;
                                    default://--.-.--
                                      break;
                                  }
                                  break;
                                default://--.-.-
                                  break;
                              }
                              break;
                            default://--.-.
                              break;
                          }
                          break;
                        case '_'://--.--
                          switch (letter[5]) {
                            case '.'://--.--.
                              switch (letter[6]) {
                                case '.'://--.--..
                                  switch (letter[7]) {
                                    case '.'://--.--...
                                      break;
                                    case '_'://--.--..-
                                      break;
                                    default://--.--..
                                      break;
                                  }
                                  break;
                                case '_'://--.--.-
                                  switch (letter[7]) {
                                    case '.'://--.--.-.
                                      break;
                                    case '_'://--.--.--
                                      break;
                                    default://--.--.-
                                      break;
                                  }
                                  break;
                                default://--.--.
                                  break;
                              }
                              break;
                            case '_'://--.---
                              switch (letter[6]) {
                                case '.'://--.---.
                                  switch (letter[7]) {
                                    case '.'://--.---..
                                      break;
                                    case '_'://--.---.-
                                      break;
                                    default://--.---.
                                      break;
                                  }
                                  break;
                                case '_'://--.----
                                  switch (letter[7]) {
                                    case '.'://--.----.
                                      break;
                                    case '_'://--.-----
                                      break;
                                    default://--.----
                                      break;
                                  }
                                  break;
                                default://--.---
                                  break;
                              }
                              break;
                            default://--.--
                              return 165;
                              break;
                          }
                          break;
                        default://--.-
                          return 'Q';
                          break;
                      }
                    default://--.
                      return 'G';
                      break;
                  }
                case '_'://---
                  switch (letter[3]) {
                    case '.'://---.
                      switch (letter[4]) {
                        case '.'://---..
                          switch (letter[5]) {
                            case '.'://---...
                              switch (letter[6]) {
                                case '.'://---....
                                  switch (letter[7]) {
                                    case '.'://---.....
                                      break;
                                    case '_'://---....-
                                      break;
                                    default://---....
                                      break;
                                  }
                                  break;
                                case '_'://---...-
                                  switch (letter[7]) {
                                    case '.'://---...-.
                                      break;
                                    case '_'://---...--
                                      break;
                                    default://---...-
                                      break;
                                  }
                                  break;
                                default://---...
                                  return ':';
                                  break;
                              }
                              break;
                            case '_'://---..-
                              switch (letter[6]) {
                                case '.'://---..-.
                                  switch (letter[7]) {
                                    case '.'://---..-..
                                      break;
                                    case '_'://---..-.-
                                      break;
                                    default://---..-.
                                      break;
                                  }
                                  break;
                                case '_'://---..--
                                  switch (letter[7]) {
                                    case '.'://---..--.
                                      break;
                                    case '_'://---..---
                                      break;
                                    default://---..--
                                      break;
                                  }
                                  break;
                                default://---..-
                                  break;
                              }
                              break;
                            default://---..
                              return '8';
                              break;
                          }
                          break;
                        case '_'://---.-
                          switch (letter[5]) {
                            case '.'://---.-.
                              switch (letter[6]) {
                                case '.'://---.-..
                                  switch (letter[7]) {
                                    case '.'://---.-...
                                      break;
                                    case '_'://---.-..-
                                      break;
                                    default://---.-..
                                      break;
                                  }
                                  break;
                                case '_'://---.-.-
                                  switch (letter[7]) {
                                    case '.'://---.-.-.
                                      break;
                                    case '_'://---.-.--
                                      break;
                                    default://---.-.-
                                      break;
                                  }
                                  break;
                                default://---.-.
                                  break;
                              }
                              break;
                            case '_'://---.--
                              switch (letter[6]) {
                                case '.'://---.--.
                                  switch (letter[7]) {
                                    case '.'://---.--..
                                      break;
                                    case '_'://---.--.-
                                      break;
                                    default://---.--.
                                      break;
                                  }
                                  break;
                                case '_'://---.---
                                  switch (letter[7]) {
                                    case '.'://---.---.
                                      break;
                                    case '_'://---.----
                                      break;
                                    default://---.---
                                      break;
                                  }
                                  break;
                                default://---.--
                                  break;
                              }
                              break;
                            default://---.-
                              break;
                          }
                          break;
                        default://---.
                          return 153;
                          break;
                      }
                      break;
                    case '_'://----
                      switch (letter[4]) {
                        case '.'://----.
                          switch (letter[5]) {
                            case '.'://----..
                              switch (letter[6]) {
                                case '.'://----...
                                  switch (letter[7]) {
                                    case '.'://----....
                                      break;
                                    case '_'://----...-
                                      break;
                                    default://----...
                                      break;
                                  }
                                  break;
                                case '_'://----..-
                                  switch (letter[7]) {
                                    case '.'://----..-.
                                      break;
                                    case '_'://----..--
                                      break;
                                    default://----..-
                                      break;
                                  }
                                  break;
                                default://----..
                                  break;
                              }
                              break;
                            case '_'://----.-
                              switch (letter[6]) {
                                case '.'://----.-.
                                  switch (letter[7]) {
                                    case '.'://----.-..
                                      break;
                                    case '_'://----.-.-
                                      break;
                                    default://----.-.
                                      break;
                                  }
                                  break;
                                case '_'://----.--
                                  switch (letter[7]) {
                                    case '.'://----.--.
                                      break;
                                    case '_'://----.---
                                      break;
                                    default://----.--
                                      break;
                                  }
                                  break;
                                default://----.-
                                  break;
                              }
                              break;
                            default://----.
                              return '9';
                              break;
                          }
                          break;
                        case '_'://-----
                          switch (letter[5]) {
                            case '.'://-----.
                              switch (letter[6]) {
                                case '.'://-----..
                                  switch (letter[7]) {
                                    case '.'://-----...
                                      break;
                                    case '_'://-----..-
                                      break;
                                    default://-----..
                                      break;
                                  }
                                  break;
                                case '_'://-----.-
                                  switch (letter[7]) {
                                    case '.'://-----.-.
                                      break;
                                    case '_'://-----.--
                                      break;
                                    default://-----.-
                                      break;
                                  }
                                  break;
                                default://-----.
                                  break;
                              }
                              break;
                            case '_'://------
                              switch (letter[6]) {
                                case '.'://------.
                                  switch (letter[7]) {
                                    case '.'://------..
                                      break;
                                    case '_'://------.-
                                      break;
                                    default://------.
                                      break;
                                  }
                                  break;
                                case '_'://-------
                                  switch (letter[7]) {
                                    case '.'://-------.
                                      break;
                                    case '_'://--------
                                      break;
                                    default://-------
                                      break;
                                  }
                                  break;
                                default://------
                                  break;
                              }
                              break;
                            default://-----
                              return '0';
                              break;
                          }
                          break;
                        default://----
                          break;
                      }
                      break;
                    default://---
                      return 'O';
                      break;
                  }
                  break;
                default://--
                  return 'M';
                  break;
              }
              break;
            default://-
              return 'T';
              break;
          }
          break;
        default:
          //report problem
          break;
      }
      return '|';
    }

    String getoutPut() {
      return outPut;
    }
};
