#include "test.h"


void test::run_all()
{
  get_pixel();
}

void test::get_pixel()
{
  cv::Mat img = cv::imread("assets/test/test.png", cv::IMREAD_COLOR);
  
  auto test = [img](Color col, Pos pos){
    if(col != c::get_pixel(img, pos))
    {
      std::string error_msg = "Test failed at pos: (" + std::to_string(pos.x)+"," + std::to_string(pos.y) + ")";
      error_msg += "\nExpected " + col.get()+ ", but got: " + c::get_pixel(img,pos).get();
      throw std::runtime_error(error_msg.c_str());
    }
  };  
  
try
{
  test(Color(23,0,251), Pos(10,10));
  test(Color(23,0,251), Pos(10,110));
  test(Color(23,0,251), Pos(10,210));
  test(Color(23,0,251), Pos(10,310));
  test(Color(5,251,0), Pos(10,410));
  test(Color(4,251,0), Pos(10,510));
  test(Color(4,251,0), Pos(10,610));
  test(Color(246,246,10), Pos(10,710));
  test(Color(245,246,9), Pos(10,810));
  test(Color(245,246,10), Pos(10,910));
  test(Color(31,0,242), Pos(80,10));
  test(Color(32,0,242), Pos(80,110));
  test(Color(31,0,242), Pos(80,210));
  test(Color(31,1,242), Pos(80,310));
  test(Color(13,242,1), Pos(80,410));
  test(Color(13,242,0), Pos(80,510));
  test(Color(13,242,1), Pos(80,610));
  test(Color(237,237,19), Pos(80,710));
  test(Color(237,237,18), Pos(80,810));
  test(Color(237,237,18), Pos(80,910));
  test(Color(39,1,233), Pos(150,10));
  test(Color(40,0,233), Pos(150,110));
  test(Color(40,0,233), Pos(150,210));
  test(Color(39,0,233), Pos(150,310));
  test(Color(22,234,1), Pos(150,410));
  test(Color(23,234,0), Pos(150,510));
  test(Color(23,233,1), Pos(150,610));
  test(Color(228,229,28), Pos(150,710));
  test(Color(228,229,28), Pos(150,810));
  test(Color(229,228,27), Pos(150,910));
  test(Color(48,1,225), Pos(220,10));
  test(Color(47,1,225), Pos(220,110));
  test(Color(48,0,225), Pos(220,210));
  test(Color(48,1,225), Pos(220,310));
  test(Color(31,224,1), Pos(220,410));
  test(Color(31,224,1), Pos(220,510));
  test(Color(31,224,1), Pos(220,610));
  test(Color(220,221,36), Pos(220,710));
  test(Color(220,221,36), Pos(220,810));
  test(Color(220,221,35), Pos(220,910));
  test(Color(56,1,216), Pos(290,10));
  test(Color(56,1,216), Pos(290,110));
  test(Color(57,0,216), Pos(290,210));
  test(Color(56,0,215), Pos(290,310));
  test(Color(40,216,1), Pos(290,410));
  test(Color(40,215,1), Pos(290,510));
  test(Color(41,215,0), Pos(290,610));
  test(Color(212,212,44), Pos(290,710));
  test(Color(212,212,44), Pos(290,810));
  test(Color(212,212,45), Pos(290,910));
  test(Color(64,1,207), Pos(360,10));
  test(Color(65,1,207), Pos(360,110));
  test(Color(64,1,207), Pos(360,210));
  test(Color(64,1,207), Pos(360,310));
  test(Color(49,206,1), Pos(360,410));
  test(Color(49,207,1), Pos(360,510));
  test(Color(50,206,1), Pos(360,610));
  test(Color(203,204,53), Pos(360,710));
  test(Color(203,203,54), Pos(360,810));
  test(Color(203,204,53), Pos(360,910));
  test(Color(73,1,198), Pos(430,10));
  test(Color(73,2,198), Pos(430,110));
  test(Color(73,1,198), Pos(430,210));
  test(Color(73,1,198), Pos(430,310));
  test(Color(59,198,1), Pos(430,410));
  test(Color(58,198,1), Pos(430,510));
  test(Color(58,198,1), Pos(430,610));
  test(Color(195,196,62), Pos(430,710));
  test(Color(195,195,62), Pos(430,810));
  test(Color(194,196,62), Pos(430,910));
  test(Color(81,2,189), Pos(500,10));
  test(Color(81,1,189), Pos(500,110));
  test(Color(81,1,189), Pos(500,210));
  test(Color(81,1,189), Pos(500,310));
  test(Color(67,189,1), Pos(500,410));
  test(Color(68,189,2), Pos(500,510));
  test(Color(68,189,2), Pos(500,610));
  test(Color(186,187,70), Pos(500,710));
  test(Color(186,187,71), Pos(500,810));
  test(Color(186,187,70), Pos(500,910));
  test(Color(90,2,180), Pos(570,10));
  test(Color(90,1,180), Pos(570,110));
  test(Color(90,2,180), Pos(570,210));
  test(Color(90,1,180), Pos(570,310));
  test(Color(76,180,2), Pos(570,410));
  test(Color(77,180,1), Pos(570,510));
  test(Color(76,180,2), Pos(570,610));
  test(Color(177,179,79), Pos(570,710));
  test(Color(178,179,79), Pos(570,810));
  test(Color(177,178,79), Pos(570,910));
  test(Color(98,2,171), Pos(640,10));
  test(Color(99,2,171), Pos(640,110));
  test(Color(98,2,171), Pos(640,210));
  test(Color(98,1,171), Pos(640,310));
  test(Color(86,172,1), Pos(640,410));
  test(Color(85,172,2), Pos(640,510));
  test(Color(85,171,2), Pos(640,610));
  test(Color(21,255,0), Pos(640,710));
  test(Color(255,0,205), Pos(640,810));
  test(Color(169,170,88), Pos(640,910));
  test(Color(106,2,162), Pos(710,10));
  test(Color(106,2,162), Pos(710,110));
  test(Color(106,2,163), Pos(710,210));
  test(Color(107,2,162), Pos(710,310));
  test(Color(94,163,2), Pos(710,410));
  test(Color(95,163,2), Pos(710,510));
  test(Color(94,162,2), Pos(710,610));
  test(Color(0,255,150), Pos(710,710));
  test(Color(255,0,104), Pos(710,810));
  test(Color(161,162,96), Pos(710,910));
  test(Color(115,2,154), Pos(780,10));
  test(Color(115,2,154), Pos(780,110));
  test(Color(115,2,153), Pos(780,210));
  test(Color(115,2,153), Pos(780,310));
  test(Color(104,153,2), Pos(780,410));
  test(Color(103,154,2), Pos(780,510));
  test(Color(104,154,2), Pos(780,610));
  test(Color(0,221,255), Pos(780,710));
  test(Color(255,11,0), Pos(780,810));
  test(Color(152,154,105), Pos(780,910));
  test(Color(123,2,145), Pos(850,10));
  test(Color(124,3,145), Pos(850,110));
  test(Color(123,2,145), Pos(850,210));
  test(Color(123,3,144), Pos(850,310));
  test(Color(112,145,2), Pos(850,410));
  test(Color(113,145,3), Pos(850,510));
  test(Color(112,145,2), Pos(850,610));
  test(Color(144,146,113), Pos(850,710));
  test(Color(255,130,0), Pos(850,810));
  test(Color(144,145,114), Pos(850,910));
  test(Color(132,2,136), Pos(920,10));
  test(Color(131,2,136), Pos(920,110));
  test(Color(131,2,136), Pos(920,210));
  test(Color(132,3,136), Pos(920,310));
  test(Color(122,136,2), Pos(920,410));
  test(Color(121,136,2), Pos(920,510));
  test(Color(122,136,2), Pos(920,610));
  test(Color(167,0,255), Pos(920,710));
  test(Color(135,137,122), Pos(920,810));
  test(Color(135,137,123), Pos(920,910));
  test(Color(140,3,127), Pos(990,10));
  test(Color(140,2,127), Pos(990,110));
  test(Color(140,2,127), Pos(990,210));
  test(Color(140,2,127), Pos(990,310));
  test(Color(130,127,3), Pos(990,410));
  test(Color(131,127,3), Pos(990,510));
  test(Color(131,127,2), Pos(990,610));
  test(Color(126,128,131), Pos(990,710));
  test(Color(126,129,131), Pos(990,810));
  test(Color(126,128,131), Pos(990,910));
  test(Color(149,3,118), Pos(1060,10));
  test(Color(148,3,118), Pos(1060,110));
  test(Color(148,3,118), Pos(1060,210));
  test(Color(149,3,118), Pos(1060,310));
  test(Color(140,118,2), Pos(1060,410));
  test(Color(140,118,3), Pos(1060,510));
  test(Color(140,118,3), Pos(1060,610));
  test(Color(118,120,140), Pos(1060,710));
  test(Color(118,120,140), Pos(1060,810));
  test(Color(118,120,139), Pos(1060,910));
  test(Color(157,3,109), Pos(1130,10));
  test(Color(157,3,109), Pos(1130,110));
  test(Color(157,3,109), Pos(1130,210));
  test(Color(157,3,109), Pos(1130,310));
  test(Color(149,110,3), Pos(1130,410));
  test(Color(148,109,3), Pos(1130,510));
  test(Color(148,109,3), Pos(1130,610));
  test(Color(109,111,148), Pos(1130,710));
  test(Color(109,111,148), Pos(1130,810));
  test(Color(109,112,148), Pos(1130,910));
  test(Color(165,3,100), Pos(1200,10));
  test(Color(166,3,100), Pos(1200,110));
  test(Color(165,3,100), Pos(1200,210));
  test(Color(165,3,100), Pos(1200,310));
  test(Color(158,101,4), Pos(1200,410));
  test(Color(157,101,3), Pos(1200,510));
  test(Color(158,100,3), Pos(1200,610));
  test(Color(101,103,158), Pos(1200,710));
  test(Color(101,104,157), Pos(1200,810));
  test(Color(101,103,157), Pos(1200,910));
  test(Color(173,3,92), Pos(1270,10));
  test(Color(173,3,92), Pos(1270,110));
  test(Color(173,4,91), Pos(1270,210));
  test(Color(173,4,91), Pos(1270,310));
  test(Color(166,91,3), Pos(1270,410));
  test(Color(167,91,3), Pos(1270,510));
  test(Color(167,92,4), Pos(1270,610));
  test(Color(92,95,166), Pos(1270,710));
  test(Color(93,95,166), Pos(1270,810));
  test(Color(93,96,166), Pos(1270,910));
  test(Color(182,3,82), Pos(1340,10));
  test(Color(182,4,82), Pos(1340,110));
  test(Color(182,4,82), Pos(1340,210));
  test(Color(182,4,83), Pos(1340,310));
  test(Color(176,82,3), Pos(1340,410));
  test(Color(176,82,3), Pos(1340,510));
  test(Color(176,82,3), Pos(1340,610));
  test(Color(85,87,174), Pos(1340,710));
  test(Color(85,87,174), Pos(1340,810));
  test(Color(84,86,174), Pos(1340,910));
}
catch(const std::exception& e)
{
  std::cerr << e.what() << '\n';
  return;
}


  std::cout << "Test Successful!\n";
  return;
}


