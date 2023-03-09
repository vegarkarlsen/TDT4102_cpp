#include "Emoji.h"

// initialize center and raduis
Face::Face(Point c, int r) : center{c}, radius{r} {

}

// Face
void Face::draw(AnimationWindow& win){
    win.draw_circle(this->center, this->radius, Color::yellow, Color::black);
}

// EmptyFace TODO: does not scale if emojy moves 
EmptyFace::EmptyFace(Point c, int r) : Face{c, r}{

    int eye_y_pos = c.y - ((r)/3);
    int eye_radius = r/6;
    int whiteEyeRadius = 2;
    
    // left eye base
    leftEye.center = {c.x - ((r)/3), eye_y_pos};
    leftEye.radius = eye_radius;
    
    // lefte eye inner white
    leftWhiteEye.center = {leftEye.center.x + whiteEyeRadius /4, leftEye.center.y};
    leftWhiteEye.radius = whiteEyeRadius;
    
    // right eye base
    rightEye.center = {c.x + ((r)/3), eye_y_pos};
    rightEye.radius = eye_radius;

    // right eye inner white
    rightWhiteEye.center = {rightEye.center.x + whiteEyeRadius /4, rightEye.center.y};
    leftWhiteEye.radius = whiteEyeRadius;




}

void EmptyFace::draw(AnimationWindow& win){
    Face::draw(win);

    // FIXME: inner white does not work
    win.draw_circle(this->leftEye.center, this->leftEye.radius, Color::black);
    // win.draw_circle(this->leftWhiteEye.center, this->leftWhiteEye.radius, Color::white);
    win.draw_circle(this->rightEye.center, this->rightEye.radius, Color::black);
    // win.draw_circle(this->rightWhiteEye.center, this->rightWhiteEye.radius, Color::white);
}


// emptyFaceNormalEye
EmptyFaceNormalEye::EmptyFaceNormalEye(Point c, int r) : Face{c,r} {
    int eyePosScale = 3;
    this->radius = r/6;

    leftEyeCenter = {c.x - (r/eyePosScale), c.y - (r/eyePosScale)};
    rightEyeCenter = {c.x + (r/eyePosScale), c.y - (r/eyePosScale)};


}

void EmptyFaceNormalEye::draw(AnimationWindow& win){
    Face::draw(win);
    // lefteye
    win.draw_circle(this->leftEyeCenter, this->radius, Color::black);
    // right eye
    win.draw_circle(this->rightEyeCenter, this->radius, Color::black);

}

// normal face
NormalFace::NormalFace(Point c, int r) : EmptyFaceNormalEye{c,r}{
    this->lenght = r - (r/6);
    int yPos = r/3;

    this->width = r/6;
    this->startMouth = {c.x - lenght/2, c.y + yPos};
}

void NormalFace::draw(AnimationWindow& win){
    EmptyFaceNormalEye::draw(win);

    win.draw_rectangle(this->startMouth, this->lenght, this->width, Color::black);
}


NormalSmily::NormalSmily(Point c, int r) : EmptyFaceNormalEye{c,r} {
    this->center = c;
    this->center.y += r/3;
    
    this->width = r/2;

    this->height = r/4;

    this->start_degree = 180;

    this->end_degree = 360; 
}

void NormalSmily::draw(AnimationWindow& win){
    EmptyFaceNormalEye::draw(win);

    win.draw_arc(this->center, this->width, this->height, this->start_degree, this->end_degree);
}

// sad smily
NormalSad::NormalSad(Point c, int r) : EmptyFaceNormalEye{c,r} {
    this->center = c;
    this->center.y += r/3;
    
    this->width = r/2;

    this->height = r/4;

    this->start_degree = 0;

    this->end_degree = 180; 
}

void NormalSad::draw(AnimationWindow& win){
    EmptyFaceNormalEye::draw(win);

    win.draw_arc(this->center, this->width, this->height, this->start_degree, this->end_degree);
}


NoExpression::NoExpression(Point c, int r) : Face{c,r}{
    this->height = r/6;

    this->mouthWidth = r - r/2;
    this->eyeWidth = r/5;

    int eyeY = c.y - r/3;
    int mouthY = c.y + r/3;

    // left eye
    this->topLeftPos.push_back({c.x - r/3, eyeY});
    // right eye
    this->topLeftPos.push_back({c.x + r/3, eyeY});
    // mouth
    this->topLeftPos.push_back({c.x - r/3, mouthY});

}

void NoExpression::draw(AnimationWindow& win){
    Face::draw(win);

    // left
    win.draw_rectangle(this->topLeftPos.at(0), this->eyeWidth, this->height, Color::black);
    win.draw_rectangle(this->topLeftPos.at(1), this->eyeWidth, this->height, Color::black);
    win.draw_rectangle(this->topLeftPos.at(2), this->mouthWidth, this->height, Color::black);
}

