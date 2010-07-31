/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "SoundRoom.h"


SoundRoom::SoundRoom ( QSize size ) : m_size(size)
{

}

QPixmap* SoundRoom::getPixmap()
{
	return new QPixmap(m_size);
}