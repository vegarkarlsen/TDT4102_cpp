#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};


class Face : public Emoji{
    private:
        // should be protected??
        Point center;
        int radius;

    public:
        virtual void draw(AnimationWindow& win) override = 0;
        Face(Point c, int r);
        
        
};



struct Circle{
    Point center;
    int radius;
};

class EmptyFace: public Face{
    private:
        Circle leftEye;
        Circle leftWhiteEye;

        Circle rightEye;
        Circle rightWhiteEye;

    public:
       EmptyFace(Point c, int r);
       void draw(AnimationWindow& win);
};




class EmptyFaceNormalEye : public Face{
    private:
        int radius = 0;
        Point leftEyeCenter;
        Point rightEyeCenter;
    
    public:
        EmptyFaceNormalEye(Point c, int r);
        virtual void draw(AnimationWindow& win) override = 0;
};


class NormalFace : public EmptyFaceNormalEye{
    private:
        Point startMouth;
        int lenght;
        int width;
    public:
        NormalFace(Point c, int r);
        void draw(AnimationWindow& win);
}; 

class NormalSmily : public EmptyFaceNormalEye{
    private:
        Point center;
        int width;
        int height;
        int start_degree;
        int end_degree;
    public:
        NormalSmily(Point c, int r);
        void draw(AnimationWindow& win); 
};


class NormalSad : public EmptyFaceNormalEye{
    private:
        Point center;
        int width;
        int height;
        int start_degree;
        int end_degree; 
    public:
        NormalSad(Point c, int r);
        void draw(AnimationWindow& win);
};



class NoExpression : public Face{
    int height;
    int mouthWidth;
    int eyeWidth;
    
    vector<Point> topLeftPos;

    public:
        NoExpression(Point c, int r);
        void draw(AnimationWindow& win);
    
};

