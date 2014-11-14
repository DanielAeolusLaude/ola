/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * SunliteWidgetFactory.h
 * The WidgetFactory for SunLite widgets.
 * Copyright (C) 2014 Simon Newton
 */

#ifndef PLUGINS_USBDMX_SUNLITEWIDGETFACTORY_H_
#define PLUGINS_USBDMX_SUNLITEWIDGETFACTORY_H_

#include "ola/base/Macro.h"
#include "plugins/usbdmx/SunliteWidget.h"
#include "plugins/usbdmx/WidgetFactory.h"

namespace ola {
namespace plugin {
namespace usbdmx {

/**
 * @brief Creates SunLite widgets.
 */
class SunliteWidgetFactory : public BaseWidgetFactory<SunliteWidget> {
 public:
  SunliteWidgetFactory() {}

  bool DeviceAdded(
      WidgetObserver *observer,
      libusb_device *usb_device,
      const struct libusb_device_descriptor &descriptor);

  void DeviceRemoved(WidgetObserver *observer,
                     libusb_device *device);

 private:
  // The product ID for widgets that are missing their firmware.
  static const uint16_t EMPTY_PRODUCT_ID;
  // The product ID for widgets with the firmware.
  static const uint16_t FULL_PRODUCT_ID;
  static const uint16_t VENDOR_ID;

  DISALLOW_COPY_AND_ASSIGN(SunliteWidgetFactory);
};
}  // namespace usbdmx
}  // namespace plugin
}  // namespace ola
#endif  // PLUGINS_USBDMX_SUNLITEWIDGETFACTORY_H_
