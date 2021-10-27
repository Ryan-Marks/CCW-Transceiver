/* Method adjustment
 *  Takes two unsigned ints a and b, returns signed int of their difference a-b
 *  Tested, working 03 October 2021
 *  version 0.4 does not use adjustment(a,b)
 *  Will change time call to one with settable zero so it may not be necessary.
 */
class MorseCharacter{ 
  public:
  int adjustment(unsigned long a, unsigned long b)  {
    // returns signed integer for difference of two unsigned longs,
    // positive if a>b, negative if a<b, zero if a==b
    // note will have to recast when using return value, at least if value out of int range.
    // 03.X.21 DK
    int difference;
    if(a>b) {
      difference=(int)(a-b);
      return difference;
    }
    else  {
          difference=(int)(b-a);
      return -difference;
    }
  }
  MorseCharacter(){};


/* Method for Morse_Gen
 *  Takes on one character A-Z, 0-9, punctuation
 *  Returns string of Morse characters, for example 'A' returns ".-"
 *  Working 26 September 2021
 notes: TODO finish FCC prosign list
  Uses dot-and-dash string for readability; many using this won't know Morse.
  Between-word space may have to be corrected.  Will likely use trailing space element
  after characters, so need 6 instead of 7 space elements for interword timing.
*  David Kazdan
 */
    
    String MorseFromCharacter(char c) {
      c=toupper(c); // no Morse for lower case letters
    switch (c)  {
    case 'A':
      return(".-");
      break;
    case 'B':
      return("-...");
      break;
    case 'C':
      return("-.-.");
      break;
    case 'D':
      return("-..");
      break;
    case 'E':
      return(".");
      break;  
    case 'F':
      return("..-.");
      break;
    case 'G':
      return("--.");
      break; 
    case 'H':
      return("....");
      break;
    case 'I':
      return("..");
      break;
    case 'J':
      return(".---");
      break;
    case 'K':
      return("-.-");
      break;
    case 'L':
      return(".-..");
      break;
    case 'M':
      return("--");
      break;
    case 'N':
      return("-.");
      break;
    case 'O':
      return("---");
      break;
    case 'P':
      return(".--.");
      break;
    case 'Q':
      return("--.-");
      break;
    case 'R':
      return(".-.");
      break;
    case 'S':
      return("...");
      break;
    case 'T':
      return("-");
      break;
    case 'U':
      return("..-");
      break;  
    case 'V':
      return("...-");
      break;
    case 'W':
      return(".--");
      break;
    case 'X':
      return("-..-");
      break;
    case 'Y':
      return("-.--");
      break;      
    case 'Z':
      return("--..");
      break;

    case '1':
      return(".----");
      break;
    case '2':
      return("..---");
      break;
    case '3':
      return("...--");
      break;
    case '4':
      return("....-");
      break;
    case '5':
      return(".....");
      break;
    case '6':
      return("-....");
      break;
    case '7':
      return("--...");
      break;
    case '8':
      return("---..");
      break;      
    case '9':
      return("----.");
      break;
    case '0':
      return("-----");
      break;

    case '.':
      return(".-.-.-");
      break;
    case ',':
      return("--..--");
      break;
    case '?':
      return("..--..");
      break;
    case '/':
      return("-..-.");
      break;
    case '@': // had to do that!
      return(".--.-.");
      break;
    case ' ': // Space.  Need handler for this.
      return("SP");
      break;
    // The FCC prosign series  
    case '=': // <BT>, break between thoughts
      return("-...-");
      break;
    case '-': // <AA>, traffic handler's line end
      return(".-.-");
      break;
    case '<': // <AS>, "wait" or "stand by"
      return(".-...");
      break;
    case '>': // <AR>, "end of transmission"
      return(".-.-.");
      break;
    case '%': // <SK>, end of work ("silent key")
      return("...-.-");
      break;
    case '+': // <KN>, "over" to responding station only ("K"is over to anyone)
      return("-.--.");
      break;          
    default:  // Any other character, return null string.
      return("");
      break;
   } // switch
}; // sendMorse
};
