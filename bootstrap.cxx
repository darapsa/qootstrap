#include "bootstrap.hxx"

Bootstrap::Bootstrap(QObject *parent):
	QObject(parent),
	m_theme(Theme::Light),
	m_purpose(Purpose::None)
{
}

Bootstrap *Bootstrap::qmlAttachedProperties(QObject *object)
{
	return new Bootstrap(object);
}

Bootstrap::Theme Bootstrap::theme() const
{
	return m_theme;
}

void Bootstrap::setTheme(Bootstrap::Theme theme)
{
	if (theme == m_theme) return;
	m_theme = theme;
	emit themeChanged();
}

Bootstrap::Purpose Bootstrap::purpose() const
{
	return m_purpose;
}

void Bootstrap::setPurpose(Bootstrap::Purpose purpose)
{
	if (purpose == m_purpose) return;
	m_purpose = purpose;
	emit purposeChanged();
}
