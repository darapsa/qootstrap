#ifndef BOOTSTRAP_HXX
#define BOOTSTRAP_HXX

#include <QObject>
#include <QtQml>

class Bootstrap : public QObject
{
	Q_OBJECT
	Q_PROPERTY(Theme theme READ theme WRITE setTheme NOTIFY themeChanged)
	Q_PROPERTY(Purpose purpose READ purpose WRITE setPurpose NOTIFY purposeChanged)

	public:
		explicit Bootstrap(QObject *parent = nullptr);
		static Bootstrap *qmlAttachedProperties(QObject *object);

		enum class Theme {
			Light,
			Dark
		};

		enum class Purpose {
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
		Q_ENUM(Purpose)

		Theme theme() const;
		void setTheme(Theme theme);
		Purpose purpose() const;
		void setPurpose(Purpose purpose);

	signals:
		void themeChanged();
		void purposeChanged();

	private:
		Theme m_theme;
		Purpose m_purpose;
};

QML_DECLARE_TYPEINFO(Bootstrap, QML_HAS_ATTACHED_PROPERTIES)

#endif
