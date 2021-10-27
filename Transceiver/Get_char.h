/*
 * Get_char_from_Python.h
 * 
 * Function to read one character from Python3 client
 * and add it to the Morse_queue string
 * 
 * Not using this in version 0.4, maybe leave it out of the calling class.
 * 
 * 01 October 2021
 * DK
 */
class 
void Get_char()  {
  if(Serial.available() > 0) {
      String data = Serial.readString();
      for(int i = 0; i < data.length();i++){
        Morse_Gen.add_new_character(data.charAt(i));
      }
      //Morse_Gen.add_new_character(data);
  }
}
