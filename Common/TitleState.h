#include "State.h"
#include "StateStack.h"
#include "Background.h"

class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(GameTimer& dt);
	virtual bool		handleEvent(Command& event);


private:
	Background*			mBackgroundSprite;
	//sf::Text			mText;

	//bool				mShowText;
	//sf::Time			mTextEffectTime;
};