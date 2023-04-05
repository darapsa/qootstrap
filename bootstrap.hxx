#ifndef BOOTSTRAP_HXX
#define BOOTSTRAP_HXX

#include <QtQml>

class Bootstrap : public QQmlEngineExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)
	Q_PROPERTY(Purpose purpose READ purpose WRITE setPurpose NOTIFY purposeChanged)

	public:
		explicit Bootstrap(QObject *parent = nullptr);
		static Bootstrap *qmlAttachedProperties(QObject *object);

		enum Purpose {
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
		Q_ENUM(Purpose)
		Purpose purpose() const;
		void setPurpose(Purpose purpose);

	signals:
		void purposeChanged();

	private:
		Purpose m_purpose;
};

QML_DECLARE_TYPEINFO(Bootstrap, QML_HAS_ATTACHED_PROPERTIES)

#endif
