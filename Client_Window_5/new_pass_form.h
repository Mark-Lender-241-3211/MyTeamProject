#ifndef NEW_PASS_FORM_H
#define NEW_PASS_FORM_H

#include <QWidget>
#include "authregform.h"
#include "clientapi.h"
#include <QTimer>
#include <QMouseEvent>

namespace Ui {
class new_pass_form;
}

class new_pass_form : public QWidget
{
    Q_OBJECT

public:
    explicit new_pass_form(QWidget *parent = nullptr);
    ~new_pass_form();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    bool eventFilter(QObject *obj, QEvent *event) override;
    void resizeEvent(QResizeEvent* event) override;

public slots:
    void slot_pass_no_show(QString);

private slots:
    void on_pushButton_continue_clicked();
    void on_pushButton_exit_clicked();
    void togglePasswordVisibility(bool checked);

private:
    Ui::new_pass_form *ui;
    ClientAPI *clientApi;
    AuthRegForm *AuthReg;
    QString generatedCode;
    bool isCodeGenerated;
    QGraphicsScene* scene2;
    QTimer *passwordHideTimer;

    QPoint m_dragPosition;
    bool m_mousePressed = false;
    QPushButton *closeButton;

signals:
    void pass_ok(QString);
};

#endif // NEW_PASS_FORM_H
