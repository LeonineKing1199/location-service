#include <catch.hpp>
#include <string>

#include "csv_to_rtree.hpp"
#include "csv_grammar.hpp"
#include "csv_rows_from_range.hpp"

TEST_CASE("The csv to rtree function")
{
  SECTION("should be able to construct an rtree from a csv")
  {
    auto const csv_input = std::string{
      "\"00210\",\"Portsmouth\",\"NH\",\"43.005895\",\"-71.013202\",\"-5\",\"1\""
      "\"00211\",\"Portsmouth\",\"NH\",\"43.005895\",\"-71.013202\",\"-5\",\"1\""
      "\"00212\",\"Portsmouth\",\"NH\",\"43.005895\",\"-71.013202\",\"-5\",\"1\""
      "\"00213\",\"Portsmouth\",\"NH\",\"43.005895\",\"-71.013202\",\"-5\",\"1\""
      "\"00214\",\"Portsmouth\",\"NH\",\"43.005895\",\"-71.013202\",\"-5\",\"1\""
      "\"00215\",\"Portsmouth\",\"NH\",\"43.005895\",\"-71.013202\",\"-5\",\"1\""
      "\"00501\",\"Holtsville\",\"NY\",\"40.922326\",\"-72.637078\",\"-5\",\"1\"" 
      "\"00544\",\"Holtsville\",\"NY\",\"40.922326\",\"-72.637078\",\"-5\",\"1\""    
    };

    auto const begin = csv_input.begin();
    auto const end   = csv_input.end();

    auto const csv_rows = csv_rows_from_range(begin, end);

    REQUIRE(csv_rows.size() == 8);

    auto const rtree = csv_rows_to_rtree(csv_rows);

    REQUIRE(rtree.size() == csv_rows.size());
  }
}