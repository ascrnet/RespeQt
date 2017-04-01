#ifndef ATARIPRINTER_H
#define ATARIPRINTER_H

#include "baseprinter.h"
#include "atasciiinternational.h"
#include "sioworker.h"

class AtariPrinter : public BasePrinter
{
    Q_OBJECT
public:
    AtariPrinter(SioWorker *worker);

    virtual bool requiresNativePrinter() const { return true; }

    bool internationalMode() const { return mInternational; }
    void setInternationalMode(bool internationalMode) { mInternational = internationalMode; }

    virtual const QChar translateAtascii(const char b);
protected:
    bool mInternational;
    AtasciiInternational mAtasciiInternational;
};

#endif // ATARIPRINTER_H
