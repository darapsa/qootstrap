#ifndef BOOTSTRAP_HXX
#define BOOTSTRAP_HXX

#include <QtQml>
#include <QColor>

class Qootstrap : public QQmlEngineExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.darapsa.Qootstrap" FILE "Qootstrap.json")
};

class Bootstrap : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")
	Q_PROPERTY(Mode mode READ mode WRITE setMode NOTIFY modeChanged)
	Q_PROPERTY(Theme theme READ theme WRITE setTheme NOTIFY themeChanged)
	Q_PROPERTY(QColor bodyColor READ bodyColor NOTIFY bodyColorChanged)
	Q_PROPERTY(QColor bodyBg READ bodyBg NOTIFY bodyBgChanged)
	Q_PROPERTY(QColor borderColor READ borderColor
			NOTIFY borderColorChanged)
	QML_ELEMENT
	QML_UNCREATABLE("Bootstrap is an attached property")

	public:
		explicit Bootstrap(QObject *parent = nullptr);
		static Bootstrap *qmlAttachedProperties(QObject *object);

		enum Mode {
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

		QColor bodyColor() const;
		QColor bodyBg() const;
		QColor borderColor() const;

	signals:
		void themeChanged();
		void modeChanged();
		void bodyColorChanged();
		void bodyBgChanged();
		void borderColorChanged();

	private:
		Mode bsMode;
		Theme bsTheme;
		QVector<QColor> bodyColors;
		QVector<QColor> bodyBgs;
		QVector<QColor> borderColors;
};

QML_DECLARE_TYPEINFO(Bootstrap, QML_HAS_ATTACHED_PROPERTIES)

#endif
