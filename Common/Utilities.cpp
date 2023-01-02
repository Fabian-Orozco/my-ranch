#include "Colors.hpp"

#include <strings.h> /* strcasecmp (ask)*/

#include <chrono> /**/
#include <iostream> /*cout endl*/
#include <string>

// ============================================================================
// print "start" and print endl
static void program_start_txt() {
  std::cout << "\nStart...\n";
  std::cout << std::endl;
}

// ============================================================================
// print "pressEnter" + getc and return 0
static int program_finish_txt() {
  std::cout << "\nPress ENTER to finish...";
  getc(stdin);
  std::cout << std::endl;
  return 0;
}

// ============================================================================
// reset the text color and print endl
static const char* text_flush() {
  std::cout << txt_reset << std::endl;
  return "";
}

// ============================================================================
// print the number and respective symbol in the ascii table from min to max
static void print_seq_ascii(const int64_t& min, const int64_t& max) {
  int64_t counter = 0;
  for (size_t simbol = min; simbol <= max; ++simbol, ++counter) {
    if (counter % 10 == 0 && counter != 0) std::cout << "\n" << std::endl;
    std::cout << "  ";
    std::cout << txt_bg_blue << txt_white << " " << simbol << " " << txt_bg_red
      << " " << (char) simbol << " " << txt_reset << " ";
  }
  std::cout << std::endl;
}

// ============================================================================
// print extended ascii codes
static void print_ext_ascii() {
  std::cout << txt_bold << "\n\nExtended ASCII codes  " << txt_bg_white
  << txt_black << "[128, 255]" << text_flush();
  print_seq_ascii(128, 255);  // inclusive
}

// ============================================================================
// the input defines whether(yes) or not to print the extended form of ascii
static void ask_print_ext_ascii() {
  std::cout << "Do you want to see ASCII extended?" << std::endl;
  std::string response;
  std::cin >> response;
  if (strcasecmp(response.c_str(), "yes") == 0
    || strcasecmp(response.c_str(), "si") == 0
    || strcasecmp(response.c_str(), "1") == 0) {
    print_ext_ascii();
  } else {
    std::cout << "Ok" << std::endl;
  }
}

// ============================================================================
// print the first 128 ascii codes
static void print_ascii() {
  std::cout << txt_bold << "Control characters  " << txt_bg_white << txt_black
    << "[0, 31]" << text_flush() << txt_bg_blue << txt_white << " 0 "
    << txt_bg_red << " null " << text_flush();

  std::cout << txt_bold << "\n\nPrintable characters  " << txt_bg_white
  << txt_black << "[32, 127]" << text_flush() << txt_bg_blue << txt_white
  << " 32 " << txt_bg_red << " Space " << text_flush();

  std::cout << txt_bold << "\n\n  Punctuation marks  " << txt_bg_white
  << txt_black  << "{33, 47}" << txt_reset << std::endl;
  print_seq_ascii(33, 47);  // inclusive

  std::cout << txt_bold << "\n\n  Integers  " << txt_bg_white << txt_black
    << "{48, 57}" << txt_reset << std::endl;
  print_seq_ascii(48, 57);  // inclusive

  std::cout << txt_bold << "\n\n  Simbols  " << txt_bg_white << txt_black
    << "{58, 64}" << txt_reset << std::endl;
  print_seq_ascii(58, 64);  // inclusive

  std::cout << txt_bold << "\n\n  Alphabet (cap)  " << txt_bg_white << txt_black
    << "{65, 90}" << txt_reset << std::endl;
  print_seq_ascii(65, 90);  // inclusive

  std::cout << txt_bold << "\n\n  Simbols  " << txt_bg_white << txt_black
    << "{91, 96}" << txt_reset << std::endl;
  print_seq_ascii(91, 96);  // inclusive

  std::cout << txt_bold << "\n\n  Alphabet (low)  " << txt_bg_white << txt_black
    << "{97, 122}" << txt_reset << std::endl;
  print_seq_ascii(97, 122);  // inclusive

  std::cout << txt_bold << "\n\n  Simbols  " << txt_bg_white << txt_black
    << "{123, 126}" << txt_reset << std::endl;
  print_seq_ascii(123, 126);  // inclusive

  std::cout << text_flush() << txt_bg_blue << txt_white << " 127 "
    << txt_bg_red << " delete " << text_flush();

  ask_print_ext_ascii();
}

// ============================================================================