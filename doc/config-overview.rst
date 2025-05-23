.. index:: Configuration Overview

Configuration
=============

Gerbera is highly configurable and allows the user to set various options and preferences that define the server's
behavior. Rather than enforcing certain features upon the user, we prefer to offer a number of choices where possible.
The heart of Gerbera configuration is the config.xml file, which is located in the ``~/.config/gerbera`` directory.
If the configuration file is not found in the default location and no configuration was specified on the command line,
Gerbera will generate a default config.xml file in the ``~/.config/gerbera`` directory. The file is in the XML format and can
be edited by a simple text editor, here is the list of all available options:

.. _extend:

-  **Required** means that the server will not start if the tag is missing in the configuration.

-  **Optional**  means that the tag can be left out of the configuration file.

-  **Default**  contains the value or values if the section, entry or attribute is omitted. Sections with complex default values are completely overwriitwn by config file content.

-  **Extensible Default**  means that the additional attribute ``extend="true"`` can be used to keep the list of default values and the config entries are added. The default values can be found in the output of ``gerbera --create-example-config``.

The root tag of Gerbera configuration is:

.. code-block:: xml

    <?xml version="1.0" encoding="UTF-8"?>
    <config version="2"
        xmlns="http://mediatomb.cc/config/2"
        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xsi:schemaLocation="http://mediatomb.cc/config/2 http://mediatomb.cc/config/2.xsd">
        ...
    </config>

The server configuration file has several options.  Below are links to the configuration sections


* :doc:`Server </config-server>`
* :doc:`Extended Runtime Options </config-extended>`
* :doc:`Clients </config-clients>`
* :doc:`Import Content </config-import>`
* :doc:`Online Content </config-online>`
* :doc:`Transcode Content </config-transcode>`

.. toctree::
   :maxdepth: 1
   :hidden:

   Config Generation        <config-generate>
   Server Options           <config-server>
   Extended Options         <config-extended>
   Clients                  <config-clients>
   Content Import Options   <config-import>
   Online Content Options   <config-online>
   Transcoding Options      <config-transcode>
