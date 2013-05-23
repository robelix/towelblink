#include "tlc_config.h"
#include "Tlc5940.h"
#include "BlinkenWall.h"
#include "towel_animations.h"

/* delay 150 ms, black default background */
BlinkenWall blinkenWall(50, 0);



static int aniFrame[] = {99,99,99,99,99,99,99,99,99,99,99};
static int aniTop[] = {0,0,0,0,0,0,0,0,0,0,0};
static int aniLeft[] = {0,0,0,0,0,0,0,0,0,0,0};
static int aniColor[] = {0,0,0,0,0,0,0,0,0,0,0};
static int currentColor = 0;

void
setup()
{
    blinkenWall.setup();
    randomSeed(analogRead(0));
}

void
loop() {
  
  for (int i=0; i<8; i++) {
    run_ani(i);
  }
  
    
  blinkenWall.update();
  blinkenWall.clear();
}

void run_ani(int aninr) {
  if (aniFrame[aninr] >= 18) {
    if(random(0,8) == 0) {
      reset_ani(aninr);
    }
  }
  if (aniFrame[aninr] < 18) {
    draw_single_frame(aniFrame[aninr], aniTop[aninr], aniLeft[aninr], aniColor[aninr]);
  }
  aniFrame[aninr]++;
}

void reset_ani(int aninr) {
  aniFrame[aninr] = 0;
  
  // mehr die im oberen teil starten
  int top = random(-5,8);
  if(top < -1) {
    top = top + 4;
  }
  aniTop[aninr] = top;
  aniLeft[aninr] = random(0,12);
  
  // anicolor nur selten ändern
  if(random(0,100) == 1) {
    currentColor = random(0,3);
  }
  aniColor[aninr] = currentColor;
}


void draw_single_frame(int framenr, int topstart, int xpos, int color) {
  if (framenr <= 1) {
      //blinkenWall.drawAnimation(&greenBrightSpot, topstart, xpos, 0, 0);
      draw_bright_spot(color, topstart, xpos);
  } else if(framenr < 10) {
      draw_fade_ani(color, topstart+framenr-8, xpos, framenr-2);
  } else {
      draw_fade_ani(color, topstart+framenr-8, xpos, 7);
  }
}

void draw_bright_spot(int color, int y, int x) {
  if (color==0) {
      blinkenWall.drawAnimation(&greenBrightSpot, y, x, 0, 0);
  }else if (color==1) {
      blinkenWall.drawAnimation(&redBrightSpot, y, x, 0, 0);
  }else {
      blinkenWall.drawAnimation(&blueBrightSpot, y, x, 0, 0);
  }
}

void draw_fade_ani(int color, int y, int x, int framenr) {
  if (color==0) {
      blinkenWall.drawAnimation(&greenFader, y, x, 0, framenr);
  }else if (color==1) {
      blinkenWall.drawAnimation(&redFader, y, x, 0, framenr);
  }else {
      blinkenWall.drawAnimation(&blueFader, y, x, 0, framenr);
  }
}
