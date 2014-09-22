#include <QtCore/QString>
#include <QtTest/QtTest>

class BenchmarkTestTest : public QObject
{
    Q_OBJECT
    
public:
    BenchmarkTestTest();
    
private Q_SLOTS:
    void testCase1();
};

BenchmarkTestTest::BenchmarkTestTest()
{
}

void BenchmarkTestTest::testCase1()
{

    //Codigo de ejemplo para realizar un benchmark
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    QBENCHMARK {
        str1.localeAwareCompare(str2);
    }
}

int main( int argc, char** argv )
{

    QCoreApplication a(argc, argv);
    int result = 0;
    freopen("Benchmark.xml", "w", stdout);
    result |= QTest::qExec(new BenchmarkTestTest, argc, argv);
    return result;

}


//QTEST_APPLESS_MAIN(BenchmarkTestTest)

#include "tst_benchmarktesttest.moc"
