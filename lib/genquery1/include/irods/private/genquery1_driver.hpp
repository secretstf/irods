#ifndef IRODS_GENQUERY1_DRIVER_HPP
#define IRODS_GENQUERY1_DRIVER_HPP

struct GenQueryInp;

#include "irods/private/genquery1_scanner.hpp"

#include "parser.hpp" // Generated by Bison.

#ifndef yyFlexLexerOnce
#  undef yyFlexLexer
#  define yyFlexLexer gq1FlexLexer
#  include <FlexLexer.h>
#endif // yyFlexLexerOnce

#include <string>

namespace irods::experimental::genquery1
{
    class driver
    {
      public:
        driver() = default;

        auto parse(const std::string& _s) -> int;

        // The GenQuery1 input structure to fill.
        GenQueryInp* gq_input = nullptr;

        // The Flex scanner implementation.
        scanner lexer;

        // Holds the current location of the parser.
        gq1::location location;

        // Used by the lexer to capture string literals.
        // This aids in handling escape sequences.
        std::string string_literal;
    }; // class driver
} // namespace irods::experimental::genquery1

#endif // IRODS_GENQUERY1_DRIVER_HPP
