#include <iostream>

#include <benchmark/benchmark.h>

#include "sudoku.hpp"
#include "puzzles.hpp"
#include "sudoku_puzzles.hpp"

using namespace sudoku_puzzles;

static void BM_PUZZLE_1(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p01);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_1);

static void BM_PUZZLE_2(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p02);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_2);

static void BM_PUZZLE_3(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p03);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_3);

static void BM_PUZZLE_4(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p04);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_4);

static void BM_PUZZLE_5(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p05);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_5);

static void BM_PUZZLE_6(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p06);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_6);

static void BM_PUZZLE_7(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p07);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_7);

static void BM_PUZZLE_8(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p08);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_8);

static void BM_PUZZLE_9(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p09);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_9);

static void BM_PUZZLE_10(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p10);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_10);

static void BM_PUZZLE_11(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p11);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_11);

static void BM_PUZZLE_12(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p12);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_12);

static void BM_PUZZLE_13(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p13);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_13);

static void BM_PUZZLE_14(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p14);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_14);

static void BM_PUZZLE_15(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p15);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_15);

static void BM_PUZZLE_16(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p16);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_16);

static void BM_PUZZLE_17(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p17);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_17);

static void BM_PUZZLE_18(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p18);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_18);

static void BM_PUZZLE_19(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p19);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_19);

static void BM_PUZZLE_20(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p20);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_20);


static void BM_PUZZLE_21(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p21);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_21);

static void BM_PUZZLE_22(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p22);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_22);

static void BM_PUZZLE_23(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p23);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_23);

static void BM_PUZZLE_24(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p24);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_24);

static void BM_PUZZLE_25(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p25);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_25);

static void BM_PUZZLE_26(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p26);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_26);

static void BM_PUZZLE_27(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p27);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_27);

static void BM_PUZZLE_28(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p28);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_28);

static void BM_PUZZLE_29(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p29);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_29);

static void BM_PUZZLE_30(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p30);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_30);
static void BM_PUZZLE_31(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p31);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_31);

static void BM_PUZZLE_32(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p32);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_32);

static void BM_PUZZLE_33(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p33);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_33);

static void BM_PUZZLE_34(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p34);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_34);

static void BM_PUZZLE_35(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p35);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_35);

static void BM_PUZZLE_36(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p36);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_36);

static void BM_PUZZLE_37(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p37);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_37);

static void BM_PUZZLE_38(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p38);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_38);

static void BM_PUZZLE_39(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p39);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_39);

static void BM_PUZZLE_40(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p40);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_40);


static void BM_PUZZLE_41(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p41);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_41);

static void BM_PUZZLE_42(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p42);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_42);

static void BM_PUZZLE_43(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p43);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_43);

static void BM_PUZZLE_44(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p44);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_44);

static void BM_PUZZLE_45(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p45);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_45);

static void BM_PUZZLE_46(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p46);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_46);

static void BM_PUZZLE_47(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p47);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_47);

static void BM_PUZZLE_48(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p48);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_48);

static void BM_PUZZLE_49(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p49);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_49);

static void BM_PUZZLE_50(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1(p50);
      s1.solve_puzzle();
   }
}
BENCHMARK(BM_PUZZLE_50);


static void BM_PUZZLE_BACKTRACK(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
   for (auto _ : state) {
      sudoku s1("300200000000107000706030500070009080900020004010800050009040301000702000000008006");
      s1.solve_backtrack();
   }
}
BENCHMARK(BM_PUZZLE_BACKTRACK);

// static void BM_PUZZLE_BACKTRACK_HARD(benchmark::State& state) {
//    for (auto _ : state) {
//       sudoku s1("000000000000003085001020000000507000004000100090000000500000073002010000000040009");
//       s1.solve_backtrack();
//    }
// }
// BENCHMARK(BM_PUZZLE_BACKTRACK_HARD);

static void BM_EULER(benchmark::State& state) {
   for (auto _ : state) {
      std::vector<std::string> puzzle_strings {
         "003020600900305001001806400008102900700000008006708200002609500800203009005010300",
         "200080300060070084030500209000105408000000000402706000301007040720040060004010003",
         "000000907000420180000705026100904000050000040000507009920108000034059000507000000",
         "030050040008010500460000012070502080000603000040109030250000098001020600080060020",
         "020810740700003100090002805009040087400208003160030200302700060005600008076051090",
         "100920000524010000000000070050008102000000000402700090060000000000030945000071006",
         "043080250600000000000001094900004070000608000010200003820500000000000005034090710",
         "480006902002008001900370060840010200003704100001060049020085007700900600609200018",
         "000900002050123400030000160908000000070000090000000205091000050007439020400007000",
         "001900003900700160030005007050000009004302600200000070600100030042007006500006800",
         "000125400008400000420800000030000095060902010510000060000003049000007200001298000",
         "062340750100005600570000040000094800400000006005830000030000091006400007059083260",
         "300000000005009000200504000020000700160000058704310600000890100000067080000005437",
         "630000000000500008005674000000020000003401020000000345000007004080300902947100080",
         "000020040008035000000070602031046970200000000000501203049000730000000010800004000",
         "361025900080960010400000057008000471000603000259000800740000005020018060005470329",
         "050807020600010090702540006070020301504000908103080070900076205060090003080103040",
         "080005000000003457000070809060400903007010500408007020901020000842300000000100080",
         "003502900000040000106000305900251008070408030800763001308000104000020000005104800",
         "000000000009805100051907420290401065000000000140508093026709580005103600000000000",
         "020030090000907000900208005004806500607000208003102900800605007000309000030020050",
         "005000006070009020000500107804150000000803000000092805907006000030400010200000600",
         "040000050001943600009000300600050002103000506800020007005000200002436700030000040",
         "004000000000030002390700080400009001209801307600200008010008053900040000000000800",
         "360020089000361000000000000803000602400603007607000108000000000000418000970030014",
         "500400060009000800640020000000001008208000501700500000000090084003000600060003002",
         "007256400400000005010030060000508000008060200000107000030070090200000004006312700",
         "000000000079050180800000007007306800450708096003502700700000005016030420000000000",
         "030000080009000500007509200700105008020090030900402001004207100002000800070000090",
         "200170603050000100000006079000040700000801000009050000310400000005000060906037002",
         "000000080800701040040020030374000900000030000005000321010060050050802006080000000",
         "000000085000210009960080100500800016000000000890006007009070052300054000480000000",
         "608070502050608070002000300500090006040302050800050003005000200010704090409060701",
         "050010040107000602000905000208030501040070020901080406000401000304000709020060010",
         "053000790009753400100000002090080010000907000080030070500000003007641200061000940",
         "006080300049070250000405000600317004007000800100826009000702000075040190003090600",
         "005080700700204005320000084060105040008000500070803010450000091600508007003010600",
         "000900800128006400070800060800430007500000009600079008090004010003600284001007000",
         "000080000270000054095000810009806400020403060006905100017000620460000038000090000",
         "000602000400050001085010620038206710000000000019407350026040530900020007000809000",
         "000900002050123400030000160908000000070000090000000205091000050007439020400007000",
         "380000000000400785009020300060090000800302009000040070001070500495006000000000092",
         "000158000002060800030000040027030510000000000046080790050000080004070100000325000",
         "010500200900001000002008030500030007008000500600080004040100700000700006003004050",
         "080000040000469000400000007005904600070608030008502100900000005000781000060000010",
         "904200007010000000000706500000800090020904060040002000001607000000000030300005702",
         "000700800006000031040002000024070000010030080000060290000800070860000500002006000",
         "001007090590080001030000080000005800050060020004100000080000030100020079020700400",
         "000003017015009008060000000100007000009000200000500004000000020500600340340200000",
         "300200000000107000706030500070009080900020004010800050009040301000702000000008006"
      };
      int total = 0;

      for(const auto& p : puzzle_strings) {
         sudoku s(p);
         s.solve_puzzle();
         total += (s.get_puzzle()[0][0] * 100) + (s.get_puzzle()[0][1] * 10) + (s.get_puzzle()[0][2]);
      }
   }
}
BENCHMARK(BM_EULER);

static void BM_SUDOKU_STRING_CONSTRUCTOR(benchmark::State& state) {
   using namespace sudoku_puzzles::string_constructor;

   for (auto _ : state) {
      sudoku s(p1);
   }
}
BENCHMARK(BM_SUDOKU_STRING_CONSTRUCTOR);

static void BM_SUDOKU_OPERATOR_EQUAL(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
      sudoku s1(p01);
      sudoku s2(p01);

   for (auto _ : state) {
      benchmark::DoNotOptimize(s1 == s2);
   }
}
BENCHMARK(BM_SUDOKU_OPERATOR_EQUAL);

static void BM_SUDOKU_OPERATOR_NOT_EQUAL(benchmark::State& state) {
   using namespace sudoku_puzzles::euler;
      sudoku s1(p01);
      sudoku s2(p01);

   for (auto _ : state) {
      benchmark::DoNotOptimize(s1 != s2);
   }
}
BENCHMARK(BM_SUDOKU_OPERATOR_NOT_EQUAL);

static void BM_SUDOKU_SET_CANDIDATES(benchmark::State& state) {
   using namespace set_candidates;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.set_candidates();
   }
}
BENCHMARK(BM_SUDOKU_SET_CANDIDATES);

static void BM_SUDOKU_HIDDEN_SINGLES(benchmark::State& state) {
   using namespace hidden_singles;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.solve_hidden_singles();
   }
}
BENCHMARK(BM_SUDOKU_HIDDEN_SINGLES);

static void BM_SUDOKU_NAKED_PAIRS(benchmark::State& state) {
   using namespace naked_pairs;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.reduce_naked_pairs();
   }
}
BENCHMARK(BM_SUDOKU_NAKED_PAIRS);

static void BM_SUDOKU_HIDDEN_PAIRS_COLUMN(benchmark::State& state) {
   using namespace hidden_pairs_column;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.find_hidden_pairs();
   }
}
BENCHMARK(BM_SUDOKU_HIDDEN_PAIRS_COLUMN);

static void BM_SUDOKU_HIDDEN_PAIRS_ROW(benchmark::State& state) {
   using namespace hidden_pairs_row;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.find_hidden_pairs();
   }
}
BENCHMARK(BM_SUDOKU_HIDDEN_PAIRS_ROW);

static void BM_SUDOKU_POINTING_PAIR(benchmark::State& state) {
   using namespace pointing_pair;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.reduce_pointing_pairs();
      s1.reduce_pointing_pairs();
   }
}
BENCHMARK(BM_SUDOKU_POINTING_PAIR);

static void BM_SUDOKU_REDUCE_BOX_LINE_ROW(benchmark::State& state) {
   using namespace reduce_box_line_row;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.reduce_box_line();
   }
}
BENCHMARK(BM_SUDOKU_REDUCE_BOX_LINE_ROW);

static void BM_SUDOKU_X_WING_COLUMN(benchmark::State& state) {
   using namespace reduce_x_wing_column;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.reduce_x_wing();
   }
}
BENCHMARK(BM_SUDOKU_X_WING_COLUMN);

static void BM_SUDOKU_X_WING_ROW(benchmark::State& state) {
   using namespace reduce_x_wing_row;

   for (auto _ : state) {
      sudoku s1(p1);
      s1.reduce_x_wing();
   }
}
BENCHMARK(BM_SUDOKU_X_WING_ROW);

static void BM_SUDOKU_NAKED_TRIPLE(benchmark::State& state) {
   using namespace naked_triple;
   for (auto _ : state) {
      sudoku s1(p1);
      s1.reduce_naked_triple();
   }
}
BENCHMARK(BM_SUDOKU_NAKED_TRIPLE);

static void BM_SUDOKU_HIDDEN_TRIPLE(benchmark::State& state) {
   using namespace find_hidden_triple;
 
   for (auto _ : state) {
      sudoku s1(p1);
      s1.find_hidden_triple();
   }
}
BENCHMARK(BM_SUDOKU_HIDDEN_TRIPLE);

BENCHMARK_MAIN();
