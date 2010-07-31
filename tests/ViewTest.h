#ifndef ViewTEST_H
#define ViewTEST_H

#include <QtCore/QObject>
#include "../View.h"

class ViewTest : public QObject
{
Q_OBJECT
private slots:
	void initTestCase();
	void init();
	void cleanup();
	void cleanupTestCase();

	void testSuperClass();
	void testWindowSize();
	void testSpeaker();
	void testSpeakerfrequency();
	
	void bench_shadepoint();
    
protected:
	View *m_uut;
};

#endif // ViewTEST_H
