#ifndef BOOTSTRAP_HXX
#define BOOTSTRAP_HXX

#include <QFont>
#include <QColor>
#include <QtQml>

class Qootstrap : public QQmlEngineExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.darapsa.Qootstrap")
};

class Bootstrap : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")
	Q_PROPERTY(Mode mode READ mode WRITE setMode NOTIFY modeChanged)
	Q_PROPERTY(Theme theme READ theme WRITE setTheme NOTIFY themeChanged)
	Q_PROPERTY(QString fontSansSerif READ fontSansSerif
			NOTIFY fontSansSerifChanged)
	Q_PROPERTY(QFont bodyFont READ bodyFont NOTIFY bodyFontChanged)
	Q_PROPERTY(QColor bodyColor READ bodyColor NOTIFY bodyColorChanged)
	Q_PROPERTY(QColor bodyBg READ bodyBg NOTIFY bodyBgChanged)
	Q_PROPERTY(QColor borderColor READ borderColor
			NOTIFY borderColorChanged)
	Q_PROPERTY(int heading READ heading WRITE setHeading
			NOTIFY headingChanged)
	Q_PROPERTY(QFont headingFont READ headingFont NOTIFY headingFontChanged)
	Q_PROPERTY(QColor headingColor READ headingColor
			NOTIFY headingColorChanged)
	Q_PROPERTY(QColor cardBg READ cardBg NOTIFY cardBgChanged)
	QML_ELEMENT
	QML_UNCREATABLE("Bootstrap is an attached property")

	public:
		explicit Bootstrap(QObject *parent = nullptr);
		static Bootstrap *qmlAttachedProperties(QObject *object);

		enum class Mode {
			Light,
			Dark
		};
		Q_ENUM(Mode)
		Mode mode() const;
		void setMode(Mode mode);

		enum class Theme {
			None,
			Primary,
			Secondary,
			Success,
			Danger,
			Warning,
			Info,
			Light,
			Dark,
			Link
		};
		Q_ENUM(Theme)
		Theme theme() const;
		void setTheme(Theme theme);

		QString fontSansSerif() const;
		QFont bodyFont() const;
		QColor bodyColor() const;
		QColor bodyBg() const;
		QColor borderColor() const;

		int heading() const;
		void setHeading(int heading);
		QFont headingFont() const;
		Q_INVOKABLE qreal headingFontSize(const qreal parentWidth = .0);
		QColor headingColor() const;

		QColor cardBg() const;

	signals:
		void themeChanged();
		void modeChanged();
		void fontSansSerifChanged();
		void bodyFontChanged();
		void bodyColorChanged();
		void bodyBgChanged();
		void borderColorChanged();
		void headingChanged();
		void headingFontChanged();
		void headingColorChanged();
		void cardBgChanged();

	private:
		Mode bsMode;
		Theme bsTheme;
		QString bsFontSansSerif;
		QFont bsBodyFont;
		QVector<QColor> bodyColors;
		QVector<QColor> bodyBgs;
		QVector<QColor> borderColors;
		int htmlHeading;
		QFont bsHeadingFont;
		QVector<QColor> headingColors;
		QVector<qreal> h1FontSize;
		QVector<qreal> h2FontSize;
		QVector<qreal> h3FontSize;
		QVector<qreal> h4FontSize;
		QVector<qreal> h5FontSize;
		QVector<qreal> h6FontSize;
		QVector<QColor> cardBgs;
};

QML_DECLARE_TYPEINFO(Bootstrap, QML_HAS_ATTACHED_PROPERTIES)

#endif
