#include "QmlVlcPlayer.h"

QmlVlcPlayer::QmlVlcPlayer( QObject* parent )
    : QmlVlcPlayerProxy( &m_player, parent ),
      m_videoOutput( &m_player )
{
    m_libvlc = libvlc_new( 0, 0 );
    m_player.open( m_libvlc );
    m_videoOutput.init();
}

QmlVlcPlayer::~QmlVlcPlayer()
{
    m_player.close();
    if( m_libvlc ) {
        libvlc_free( m_libvlc );
        m_libvlc = 0;
    }
}
