#ifndef BOOTSTRAP_HXX
#define BOOTSTRAP_HXX

#include <QtQml>
#include <QColor>

class BootstrapPlugin : public QQmlEngineExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)
};

class Bootstrap : public QObject
{
	Q_OBJECT
	Q_PROPERTY(Mode mode READ mode WRITE setMode NOTIFY modeChanged)
	Q_PROPERTY(Theme theme READ theme WRITE setTheme NOTIFY themeChanged)
	Q_PROPERTY(QColor bodyBg READ bodyBg NOTIFY bodyBgChanged)
	QML_ELEMENT
	QML_UNCREATABLE("Bootstrap is an attached property")

	public:
		explicit Bootstrap(QObject *parent = nullptr);
		static Bootstrap *qmlAttachedProperties(QObject *object);

		enum Mode {
			LightMode,
			DarkMode
		};
		Q_ENUM(Mode)
		enum Theme {
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

		Mode mode() const;
		void setMode(Mode mode);
		Theme theme() const;
		void setTheme(Theme theme);
		QColor bodyBg() const;

	signals:
		void modeChanged();
		void themeChanged();
		void bodyBgChanged();

	private:
		Mode bsMode;
		Theme bsTheme;
		QColor bsLightBodyBg;
		QColor bsDarkBodyBg;
};

QML_DECLARE_TYPEINFO(Bootstrap, QML_HAS_ATTACHED_PROPERTIES)

#endif
