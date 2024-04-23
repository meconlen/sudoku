#include <iostream>

#include <gtest/gtest.h>

#include "sudoku.hpp"
#include "puzzles.hpp"

using namespace sudoku_puzzles::euler;

// solve_single_candidates
TEST(Euler, p01) 
{
   sudoku s1(p01);
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {4,8,3,9,2,1,6,5,7},
      {9,6,7,3,4,5,8,2,1},
      {2,5,1,8,7,6,4,9,3},
      {5,4,8,1,3,2,9,7,6},
      {7,2,9,5,6,4,1,3,8},
      {1,3,6,7,9,8,2,4,5},
      {3,7,2,6,8,9,5,1,4},
      {8,1,4,2,5,3,7,6,9},
      {6,9,5,4,1,7,3,8,2}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1.get_puzzle(), s2.get_puzzle());
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// solve_unique_candidates
TEST(Euler, p02) 
{
   sudoku s1(p02);
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {2,4,5,9,8,1,3,7,6},
      {1,6,9,2,7,3,5,8,4},
      {8,3,7,5,6,4,2,1,9},
      {9,7,6,1,2,5,4,3,8},
      {5,1,3,4,9,8,6,2,7},
      {4,8,2,7,3,6,9,5,1},
      {3,9,1,6,5,7,8,4,2},
      {7,2,8,3,4,9,1,6,5},
      {6,5,4,8,1,2,7,9,3}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// solve_unique_candidates
TEST(Euler, p03) 
{
   sudoku s1(p03);
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {4,6,2,8,3,1,9,5,7},
      {7,9,5,4,2,6,1,8,3},
      {3,8,1,7,9,5,4,2,6},
      {1,7,3,9,8,4,2,6,5},
      {6,5,9,3,1,2,7,4,8},
      {2,4,8,5,6,7,3,1,9},
      {9,2,6,1,7,8,5,3,4},
      {8,3,4,2,5,9,6,7,1},
      {5,1,7,6,4,3,8,9,2},
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } }

TEST(Euler, p04) 
{
   sudoku s1(p04);
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {1,3,7,2,5,6,8,4,9},
      {9,2,8,3,1,4,5,6,7},
      {4,6,5,8,9,7,3,1,2},
      {6,7,3,5,4,2,9,8,1},
      {8,1,9,6,7,3,2,5,4},
      {5,4,2,1,8,9,7,3,6},
      {2,5,6,7,3,1,4,9,8},
      {3,9,1,4,2,8,6,7,5},
      {7,8,4,9,6,5,1,2,3}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// naked pairs 
TEST(Euler, p05) 
{
   sudoku s1(p05);
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {5,2,3,8,1,6,7,4,9},
      {7,8,4,5,9,3,1,2,6},
      {6,9,1,4,7,2,8,3,5},
      {2,3,9,1,4,5,6,8,7},
      {4,5,7,2,6,8,9,1,3},
      {1,6,8,9,3,7,2,5,4},
      {3,4,2,7,8,9,5,6,1},
      {9,1,5,6,2,4,3,7,8},
      {8,7,6,3,5,1,4,9,2}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(Euler, p06) 
{
   sudoku s1(p06);
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {1,7,6,9,2,3,5,8,4},
      {5,2,4,8,1,7,6,3,9},
      {8,9,3,6,5,4,2,7,1},
      {9,5,7,3,4,8,1,6,2},
      {6,3,8,1,9,2,4,5,7},
      {4,1,2,7,6,5,3,9,8},
      {2,6,5,4,8,9,7,1,3},
      {7,8,1,2,3,6,9,4,5},
      {3,4,9,5,7,1,8,2,6}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

// we need the X-wing next 

TEST(Euler, p07) 
{
   sudoku s1(p07);
   s1.solve_puzzle();

   sudoku::puzzle_input_data_t p2 {{
      {1,4,3,9,8,6,2,5,7},
      {6,7,9,4,2,5,3,8,1},
      {2,8,5,7,3,1,6,9,4},
      {9,6,2,3,5,4,1,7,8},
      {3,5,7,6,1,8,9,4,2},
      {4,1,8,2,7,9,5,6,3},
      {8,2,1,5,6,7,4,3,9},
      {7,9,6,1,4,3,8,2,5},
      {5,3,4,8,9,2,7,1,6}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp();
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(Euler, p08)
{
   sudoku s1(p08);
   s1.solve_puzzle();
   sudoku::puzzle_input_data_t p2 {{
      {4,8,7,1,5,6,9,3,2},
      {3,6,2,4,9,8,7,5,1},
      {9,1,5,3,7,2,8,6,4},
      {8,4,6,5,1,9,2,7,3},
      {5,9,3,7,2,4,1,8,6},
      {2,7,1,8,6,3,5,4,9},
      {1,2,4,6,8,5,3,9,7},
      {7,3,8,9,4,1,6,2,5},
      {6,5,9,2,3,7,4,1,8}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(Euler, p09)
{
   sudoku s1(p09);
   s1.solve_puzzle();
   sudoku::puzzle_input_data_t p2 {{
      {8,1,4,9,7,6,5,3,2},
      {6,5,9,1,2,3,4,7,8},
      {7,3,2,8,5,4,1,6,9},
      {9,4,8,2,6,5,3,1,7},
      {2,7,5,3,4,1,8,9,6},
      {1,6,3,7,9,8,2,4,5},
      {3,9,1,6,8,2,7,5,4},
      {5,8,7,4,3,9,6,2,1},
      {4,2,6,5,1,7,9,8,3}
   }};

   sudoku s2(p2);
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   } 
}

TEST(Euler, p10)
{
   sudoku s1(p10);
   s1.solve_puzzle();
   sudoku s2("761928453925743168438615927357461289894372615216589374689154732142837596573296841");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p11)
{
   sudoku s1(p11);
   s1.solve_puzzle();
   sudoku s2("976125438158436927423879156234761895867952314519384762782513649395647281641298573");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p12)
{
   sudoku s1(p12);
   s1.solve_puzzle();
   sudoku s2("962341758148975623573268149321694875487512936695837412834726591216459387759183264");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p13)
{
   sudoku s1(p13);
   s1.solve_puzzle();
   sudoku s2("397681524645279813218534976823956741169742358754318692472893165531467289986125437");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p14)
{
   sudoku s1(p14);
   s1.solve_puzzle();
   sudoku s2("639218457471539268825674139564823791793451826218796345352987614186345972947162583");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p15)
{
   sudoku s1(p15);
   s1.solve_puzzle();
   sudoku s2("697128345428635197315479682531246978286397451974581263149852736752963814863714529");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p16)
{
   sudoku s1(p16);
   s1.solve_puzzle();
   sudoku s2("361725948587964213492831657638259471174683592259147836746392185923518764815476329");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p17)
{
   sudoku s1(p17);
   s1.solve_puzzle();
   sudoku s2("359867124648312597712549836876924351524731968193685472931476285465298713287153649");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p18)
{
   sudoku s1(p18);
   s1.solve_puzzle();
   sudoku s2("786945312219863457534271869165482973327619548498537126951728634842356791673194285");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p19)
{
   sudoku s1(p19);
   s1.solve_puzzle();
   sudoku s2("743512986589346217126987345934251768671498532852763491398675124417829653265134879");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p20)
{
   sudoku s1(p20);
   s1.solve_puzzle();
   sudoku s2("782614359439825176651937428293471865568392714147568293326749581975183642814256937");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p21)
{
   sudoku s1(p21);
   s1.solve_puzzle();
   sudoku s2("428531796365947182971268435214896573697453218583172964849615327752389641136724859");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p22)
{
   sudoku s1(p22);
   s1.solve_puzzle();
   sudoku s2("425781936178369524369524187894157362652843791713692845987216453536478219241935678");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p23)
{
   sudoku s1(p23);
   s1.solve_puzzle();
   sudoku s2("348267951571943628269185374697351482123874596854629137415798263982436715736512849");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p24)
{
   sudoku s1(p24);
   s1.solve_puzzle();
   sudoku s2("124986735867435912395712684478359261259861347631274598712698453983547126546123879");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p25)
{
   sudoku s1(p25);
   s1.solve_puzzle();
   sudoku s2("361524789789361425524879361893157642412683597657942138148796253235418976976235814");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p26)
{
   sudoku s1(p26);
   s1.solve_puzzle();
   sudoku s2("581479263329156847647328159956731428238964571714582936172695384893247615465813792");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p27)
{
   sudoku s1(p27);
   s1.solve_puzzle();
   sudoku s2("387256419469781325512439867123548976758963241694127583835674192271895634946312758");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p28)
{
   sudoku s1(p28);
   s1.solve_puzzle();
   sudoku s2("345871269279653184861429537197346852452718396683592741738264915516937428924185673");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p29)
{
   sudoku s1(p29);
   s1.solve_puzzle();
   sudoku s2("235761489419328576867549213746135928521896734983472651394287165652913847178654392");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}


TEST(Euler, p30)
{
   sudoku s1(p30);
   s1.solve_puzzle();
   sudoku s2("298175643657394128134286579821649735573821496469753281312468957785912364946537812");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p31)
{
   sudoku s1(p31);
   s1.solve_puzzle();
   sudoku s2("761543289832791645549628137374215968128936574695487321417369852953872416286154793");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p32)
{
   sudoku s1(p32);
   s1.solve_puzzle();
   sudoku s2("132649785758213649964785123543897216276531894891426537619378452327154968485962371");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p33)
{
   sudoku s1(p33);
   s1.solve_puzzle();
   sudoku s2("698173542354628179172549368531897426946312857827456913765931284213784695489265731");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p34)
{
   sudoku s1(p34);
   s1.solve_puzzle();
   sudoku s2("852716943197843652463925187278634591645179328931582476786491235314258769529367814");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p35)
{
   sudoku s1(p35);
   s1.solve_puzzle();
   sudoku s2("453218796629753481178496532796582314314967825285134679542879163937641258861325947");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p36)
{
   sudoku s1(p36);
   s1.solve_puzzle();
   sudoku s2("516289347849173256732465918698317524327954861154826739961732485275648193483591672");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p37)
{
   sudoku s1(p37);
   s1.solve_puzzle();
   sudoku s2("945681723781234965326759184269175348138942576574863219457326891612598437893417652");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p38)
{
   sudoku s1(p38);
   s1.solve_puzzle();
   sudoku s2("365942871128756493974813562819435627537268149642179358296384715753691284481527936");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p39)
{
   sudoku s1(p39);
   s1.solve_puzzle();
   sudoku s2("134587296278169354695234817359816472821473569746925183917348625462751938583692741");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p40)
{
   sudoku s1(p40);
   s1.solve_puzzle();
   sudoku s2("193672485462358971785914623538296714674135298219487356826741539941523867357869142");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p41)
{
   sudoku s1(p41);
   s1.solve_puzzle();
   sudoku s2("814976532659123478732854169948265317275341896163798245391682754587439621426517983");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p42)
{
   sudoku s1(p42);
   s1.solve_puzzle();
   sudoku s2("384567921126439785759821346563798214847312659912645873231974568495286137678153492");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p43)
{
   sudoku s1(p43);
   s1.solve_puzzle();
   sudoku s2("469158372712463859538297641927634518385719426146582793653941287294876135871325964");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p44)
{
   sudoku s1(p44);
   s1.solve_puzzle();
   sudoku s2("316549278987321645452678931594236817238417569671985324845162793129753486763894152");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p45)
{
   sudoku s1(p45);
   s1.solve_puzzle();
   sudoku s2("586127943723469851491853267135974628279618534648532179917246385352781496864395712");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p46)
{
   sudoku s1(p46);
   s1.solve_puzzle();
   sudoku s2("954213687617548923832796541763851294128974365549362178281637459475129836396485712");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p47)
{
   sudoku s1(p47);
   s1.solve_puzzle();
   sudoku s2("159743862276589431348612759624978315917235684583164297435821976861497523792356148");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p48)
{
   sudoku s1(p48);
   s1.solve_puzzle();
   sudoku s2("861357294597482361432619785916275843358964127274138956789541632143826579625793418");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p49)
{
   sudoku s1(p49);
   s1.solve_puzzle();
   sudoku s2("294863517715429638863751492152947863479386251638512974986134725521678349347295186");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

TEST(Euler, p50)
{
   sudoku s1(p50);
   s1.solve_puzzle();
   sudoku s2("351286497492157638786934512275469183938521764614873259829645371163792845547318926");
   EXPECT_EQ(s1, s2);
   EXPECT_EQ(s1.is_solved(), true);
   if(!(s1 == s2)) {
      s1.print_puzzle_cpp("p1");
      s1.print_puzzle_candidates_cpp("p1");
   }    
}

