#include "publisher.hpp"

Publisher::Publisher(unsigned int domain_id, unsigned int sample_count)
    : m_domain_id(domain_id),
      m_sample_count(sample_count),
      m_participant(domain_id),
      m_topic(m_participant, "HelloWorld Topic"),
      m_publisher(m_participant),
      m_writer(m_publisher, m_topic)
{
    // Aquí puedes realizar otras inicializaciones si es necesario
}

void Publisher::writeSample()
{
    HelloWorld sample;
    m_writer.write(sample);
    qDebug() << "writeSample";
}

