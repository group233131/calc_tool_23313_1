#ifndef EXPRESSION_CALC
#define EXPRESSION_CALC

#include <QVector>
#include <QString>
#include <QStack>

/*void SetExpression( const QString& str );
QString GetExpression();
double EvalExpression( const QVector< QString >& vars, const QVector< double >& vals );
*/

class ExpressionCalc
{
    QStack<double> m_stack; // стек операндов
    QStack<char>   m_stackOp; // стек операций
    QString        m_expr;    // исходная строка
    int            m_pos;     // индекс символа в m_expr, с котрого продолжит чтение следующий вызов ReadOperand или ReadOperation
    QVector<int>   m_opPriority; // массив приоритетов операций.
    mutable QVector< QString > m_vars;
    mutable QVector< double >  m_vals;
    double ReadOperand();
    char   ReadOperation();
    void Unwind();
public:
    ExpressionCalc( const QString& str = "" );
    void SetExpression( const QString& str );
    QString GetExpression() const;
    double Calculate( const QVector< QString >& vars, const QVector< double >& vals );
    double Calculate()
    {
        return Calculate( QVector< QString >(), QVector< double >() );
    }
};


#endif // EXPRESSION_CALC

