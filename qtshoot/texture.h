#ifndef TEXTURE_H
#define TEXTURE_H

#include <QHash>
#include <QtGui>

class Texture
{
    typedef QHash<QString, QPixmap*> QTextures;

private:
    Texture();
    QPixmap* findTexture(const QString& key);

public:
    ~Texture();
    static Texture* inst();
    void loadTexture(const QString& key, const QString& fileName);
    void deleteTexture(const QString& key);
    QPixmap& getTexture(const QString& key);

    void putSprite(const QString& key, QPainter* painter, const QPoint& dstPt, const QPoint& srcPt, const QSize& srcSize);

 private:
    QTextures   m_tex;
};


#endif // TEXTURE_H
