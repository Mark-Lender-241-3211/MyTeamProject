#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include <QGraphicsScene>
#include <QPainter>
#include <QPushButton>
#include "clientapi.h"
#include "passwordhasher.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSsl>
#include <QUrl>
#include <QTimer>
#include <QSslSocket>
#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>
#include <QRandomGenerator>
#include <QApplication>
#include <QMouseEvent>

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QDialog {
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    QString getLineEditText() const;
    static int randomValue;
    static void loadBackground(QGraphicsView* view, QGraphicsScene* scene, const QString& imagePath);

public slots:
    void slot_auth_reg_show(QString);

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_toReg_clicked();
    void on_pushButton_Auth_clicked();
    void on_pushButton_Reg_clicked();
    void on_pushButton_new_password_clicked();
    void on_pushButton_pass_new_clicked();
    void togglePasswordVisibility(bool checked);
    void hidePasswordAfterDelay();

signals:
    void reg_ok(QString);
    void auth_ok(QString);
    void pass_no(QString);

private:
    Ui::AuthRegForm *ui;
    ClientAPI *clientApi;
    QGraphicsScene *scene;
    QPushButton *closeButton;

    void change_type_to_reg(bool);
    void clear();
    bool isvalidEmail(QString email);

    int authAttempts;
    int toRegAttempts;
    QTimer *passwordHideTimer;

    QPoint m_dragPosition;
    bool m_mousePressed = false;
};

#endif // AUTHREGFORM_H
