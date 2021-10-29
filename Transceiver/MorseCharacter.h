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
      return(".-E");
      break;
    case 'B':
      return("-...E");
      break;
    case 'C':
      return("-.-.E");
      break;
    case 'D':
      return("-..E");
      break;
    case 'E':
      return(".E");
      break;  
    case 'F':
      return("..-.E");
      break;
    case 'G':
      return("--.E");
      break; 
    case 'H':
      return("....E");
      break;
    case 'I':
      return("..E");
      break;
    case 'J':
      return(".---E");
      break;
    case 'K':
      return("-.-E");
      break;
    case 'L':
      return(".-..E");
      break;
    case 'M':
      return("--E");
      break;
    case 'N':
      return("-.E");
      break;
    case 'O':
      return("---E");
      break;
    case 'P':
      return(".--.E");
      break;
    case 'Q':
      return("--.-E");
      break;
    case 'R':
      return(".-.E");
      break;
    case 'S':
      return("...E");
      break;
    case 'T':
      return("-E");
      break;
    case 'U':
      return("..-E");
      break;  
    case 'V':
      return("...-E");
      break;
    case 'W':
      return(".--E");
      break;
    case 'X':
      return("-..-E");
      break;
    case 'Y':
      return("-.--E");
      break;      
    case 'Z':
      return("--..E");
      break;

    case '1':
      return(".----E");
      break;
    case '2':
      return("..---E");
      break;
    case '3':
      return("...--E");
      break;
    case '4':
      return("....-E");
      break;
    case '5':
      return(".....E");
      break;
    case '6':
      return("-....E");
      break;
    case '7':
      return("--...E");
      break;
    case '8':
      return("---..E");
      break;      
    case '9':
      return("----.E");
      break;
    case '0':
      return("-----E");
      break;

    case '.':
      return(".-.-.-E");
      break;
    case ',':
      return("--..--E");
      break;
    case '?':
      return("..--..E");
      break;
    case '/':
      return("-..-.E");
      break;
    case '@': // had to do that!
      return(".--.-.E");
      break;
    case ' ': // Space.  Need handler for this.
      return("SP");
      break;
    // The FCC prosign series  
    case '=': // <BT>, break between thoughts
      return("-...-E");
      break;
    case '-': // <AA>, traffic handler's line end
      return(".-.-E");
      break;
    case '<': // <AS>, "wait" or "stand by"
      return(".-...E");
      break;
    case '>': // <AR>, "end of transmission"
      return(".-.-.E");
      break;
    case '%': // <SK>, end of work ("silent key")
      return("...-.-E");
      break;
    case '+': // <KN>, "over" to responding station only ("K"is over to anyone)
      return("-.--.E");
      break;          
    default:  // Any other character, return null string.
      return("");
      break;
   } // switch
}; // sendMorse
};
