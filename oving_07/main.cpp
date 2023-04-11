#include "std_lib_facilities.h"
#include "animal.h"
#include "AnimationWindow.h"
#include "Emoji.h"


#define LOG
#include "log.h"

/*
oppgave 1 a)
public: medlemsvariabler og funksjoner deklarert her kan akseseres overalt 
private: medlemsvariabler og funskjner deklarert her kan kun akseseres innad i klassen 
protected: medlemsvariabler og funskjoner deklarert her kan kun akkseseres innad i klassen, men kan også akkseseres i alle spesialiseringer (ting som arver fra klassen)
*/


/*
oppgave 1 d):
hvis man fjerner virtual forran toString i Animal klassen vil pekeren peke til
animal sin toString og bruker ikke den redefinerte funkjsonen i cat og dog
*/

void testAnimal(){
    // vector<Animal> a{{"1", 1}, {"2", 2}, {"3", 3}};
    vector<Cat> c{{"1", 1}, {"2", 2}, {"3", 3}};
    vector<Dog> d{{"1", 1}, {"2", 2}, {"3", 3}};

    for (int i = 0; i < 3; i++){
        // LOG_INFO(a.at(i).toString());
        LOG_INFO(c.at(i).toString());
        LOG_INFO(d.at(i).toString());
    }

    vector<unique_ptr<Animal>> vec;
    vec.emplace_back(new Cat{"test", 1});
    vec.emplace_back(new Dog{"petter", 3});
    vec.emplace_back(new Cat{"Nils", 7});
    vec.emplace_back(new Dog{"hei", 2});

    for (int i = 0; i < vec.size(); i++){
        LOG_INFO(vec.at(i) -> toString());
    }

}



// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;



// constructor in definiton (header) ? 

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/

    vector<unique_ptr<Emoji>> emojis;
    emojis.emplace_back(new NormalFace{{250, 250}, emojiRadius});
    emojis.emplace_back(new NormalSmily{{355, 250}, emojiRadius});
    emojis.emplace_back(new NormalSad{{460, 250}, emojiRadius});
    emojis.emplace_back(new NoExpression{{565, 250}, emojiRadius});

    for (int i = 0; i < emojis.size(); i++){
        emojis.at(i) ->draw(win);
    }


	win.wait_for_close();

	return 0;
}
