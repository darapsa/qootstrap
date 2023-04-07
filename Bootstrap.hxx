#ifndef BOOTSTRAP_HXX
#define BOOTSTRAP_HXX

#include <QtQml>
#include <QColor>

class Qootstrap : public QQmlEngineExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.darapsa.Qootstrap")
};

class Bootstrap : public QObject
{
	Q_OBJECT
	Q_PROPERTY(Theme theme READ theme WRITE setTheme NOTIFY themeChanged)
	Q_PROPERTY(bool darkMode READ darkMode WRITE setDarkMode NOTIFY darkModeChanged)
	Q_PROPERTY(QColor bodyColor READ bodyColor NOTIFY bodyColorChanged)
	Q_PROPERTY(QColor bodyBg READ bodyBg NOTIFY bodyBgChanged)
	QML_ELEMENT
	QML_UNCREATABLE("Bootstrap is an attached property")

	public:
		explicit Bootstrap(QObject *parent = nullptr);
		static Bootstrap *qmlAttachedProperties(QObject *object);

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
		Theme theme() const;
		void setTheme(Theme theme);
		bool darkMode() const;
		void setDarkMode(bool darkMode);
		QColor bodyColor() const;
		QColor bodyBg() const;

	signals:
		void themeChanged();
		void darkModeChanged();
		void bodyColorChanged();
		void bodyBgChanged();

	private:
		Theme bsTheme;
		bool bsDarkMode;
		QColor bsLightBodyColor;
		QColor bsDarkBodyColor;
		QColor bsLightBodyBg;
		QColor bsDarkBodyBg;
};

QML_DECLARE_TYPEINFO(Bootstrap, QML_HAS_ATTACHED_PROPERTIES)

#endif
