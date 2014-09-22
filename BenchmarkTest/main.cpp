#include <QtCore/QString>
#include <QtTest/QtTest>
#include "MatchTemplateTest.h"

int main( int argc, char** argv )
{

    QCoreApplication a(argc, argv);
    int result = 0;
    freopen("Benchmark.xml", "w", stdout);
    result |= QTest::qExec(new MatchTemplateTest, argc, argv);
    return result;

}
