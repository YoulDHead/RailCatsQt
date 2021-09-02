#ifndef railcats_settings
#define railcats_settings

#include <QTextEdit>

class RailCats_Settings{

	public:

		RailCats_Settings();
		~RailCats_Settings();

		// QueueElementAge
		int QueueElementAge;

        QTextEdit * logWindow;

};
#endif

