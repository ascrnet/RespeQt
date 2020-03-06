#ifndef BASEPRINTER_H
#define BASEPRINTER_H

#include "sioworker.h"
#include "atascii.h"
#include "nativeoutput.h"

#include <QByteArray>
#include <QPainter>
#include <QPrinter>
#include <QRect>
#include <QPainter>
#include <QFont>
#include <QFontMetrics>

namespace Printers
{
    class BasePrinter : public SioDevice
    {
        Q_OBJECT
    public:
        BasePrinter(SioWorker *worker);
        virtual ~BasePrinter();

        virtual void handleCommand(quint8 command, quint16 aux);
        virtual bool handleBuffer(QByteArray &buffer, unsigned int len) = 0;

        virtual const QChar translateAtascii(const unsigned char b);

        NativeOutput *output() const { return mOutput; }
        void setOutput(NativeOutput *output);

        static QString typeName()
        {
            throw new std::invalid_argument("Not implemented");
        }

    protected:
        // This should be static methods, because they are called
        // from the constructor
        virtual void setupFont() {}
        virtual void setupOutput();

        Atascii mAtascii;
        NativeOutput *mOutput;

    private:
        char m_lastOperation;

    };
}
#endif // BASEPRINTER_H