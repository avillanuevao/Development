#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>  // for sleep()
#include <rti/config/Logger.hpp>  // for logging
// Or simply include <dds/dds.hpp>
#include "hello_world.hpp"
#include "application.hpp"  // Argument parsing

#include <QDebug>

class Publisher
{
public:
    Publisher(unsigned int domain_id, unsigned int sample_count);
    void writeSample();
private:
    unsigned int m_domain_id;
    unsigned int m_sample_count;
    dds::domain::DomainParticipant m_participant;
    dds::topic::Topic<HelloWorld> m_topic;
    dds::pub::Publisher m_publisher;
    dds::pub::DataWriter<HelloWorld> m_writer;
};

#endif // PUBLISHER_HPP
