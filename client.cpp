#include "client.h"
#include "stdlib.h"

Client::Client() {
    loc = Point();
}

Client::Client(Point p, int max) {
    loc = p;
    vx = rand()%3 +1;
    vy = rand()%3 +1;
    int dir = rand()%100;
    if (dir<50){
        vx = -vx;
    }
    dir = rand()%100;
    if(dir<50){
        vy = -vy;
    }
    edge = max;
}

void Client::move() {
    double x = loc.x()+vx;
    double y = loc.y()+vy;
    if (x>edge-1) {
        x = edge-1;
    }
    if(x<0) {
        x=0;
    }

    if (y>edge-1) {
        y = edge-1;
    }
    if(y<0) {
        y=0;
    }

    loc.setX(x);
    loc.setY(y);

    if (loc.x() >= edge-1 || loc.x() <= 0 ) {
        vx = -vx;
    }

    if (loc.y() >= edge-1 || loc.y() <= 0) {
        vy = -vy;
    }
}
