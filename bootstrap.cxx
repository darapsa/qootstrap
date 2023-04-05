#include "bootstrap.hxx"

Bootstrap::Bootstrap(QObject *parent):
	QQmlEngineExtensionPlugin(parent),
	m_purpose(None)
{
}

Bootstrap *Bootstrap::qmlAttachedProperties(QObject *object)
{
	return new Bootstrap(object);
}

Bootstrap::Purpose Bootstrap::purpose() const
{
	return m_purpose;
}

void Bootstrap::setPurpose(Purpose purpose)
{
	if (purpose == m_purpose) return;
	m_purpose = purpose;
	emit purposeChanged();
}
