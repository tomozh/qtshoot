#include "texture.h"

Texture::Texture()
{
}

QPixmap* Texture::findTexture(const QString& key)
{
    QTextures::iterator it;

    if((it = m_tex.find(key)) != m_tex.end())
        return it.value();

    return NULL;
 }
Texture::~Texture()
{
    foreach(QPixmap* pic, m_tex)
        delete pic;
    m_tex.clear();
}

Texture* Texture::inst()
{
    static Texture obj;
    return &obj;
}

void Texture::loadTexture(const QString& key, const QString& fileName)
{
    QPixmap* pic;

    if((pic = findTexture(key)) == NULL)
    {
        pic = new QPixmap(fileName);
        m_tex[key] = pic;
    }
}

void Texture::deleteTexture(const QString& key)
{
    QPixmap* pic;

    if((pic = findTexture(key)) != NULL)
    {
        delete pic;
        m_tex.remove(key);
    }
}

QPixmap& Texture::getTexture(const QString& key)
{
    QPixmap* pic;
    static QPixmap dummy;

    if((pic = findTexture(key)) == NULL)
        return dummy;   // dummy
    else
        return *pic;
}




void Texture::putSprite(const QString& key, QPainter* painter, const QPoint& dstPt, const QPoint& srcPt, const QSize& srcSize)
{
    QRect srcRect(srcPt, srcSize);
    QPoint pt(dstPt);

    pt -= QPoint(srcSize.width() / 2, srcSize.height() / 2);

    QPixmap& pix = Texture::inst()->getTexture(key);
    painter->drawPixmap(pt, pix, srcRect);
}

