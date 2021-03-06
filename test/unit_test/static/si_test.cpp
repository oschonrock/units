// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <units/physical/si/acceleration.h>
#include <units/physical/si/area.h>
#include <units/physical/si/capacitance.h>
#include <units/physical/si/current.h>
#include <units/physical/si/electric_charge.h>
#include <units/physical/si/energy.h>
#include <units/physical/si/force.h>
#include <units/physical/si/frequency.h>
#include <units/physical/si/length.h>
#include <units/physical/si/luminous_intensity.h>
#include <units/physical/si/mass.h>
#include <units/physical/si/power.h>
#include <units/physical/si/pressure.h>
#include <units/physical/si/substance.h>
#include <units/physical/si/surface_tension.h>
#include <units/physical/si/temperature.h>
#include <units/physical/si/time.h>
#include <units/physical/si/velocity.h>
#include <units/physical/si/voltage.h>
#include <units/physical/si/volume.h>
#include <utility>

namespace {

using namespace units;
using namespace units::si;

/* ************** BASE DIMENSIONS **************** */

// length

static_assert(1q_km == 1000q_m);
static_assert(1q_m == 100q_cm);
static_assert(1q_m == 10q_dm);
static_assert(1q_m == 1000q_mm);
static_assert(1q_hm == 100q_m);
static_assert(1q_au == 149'597'870'700q_m);
static_assert(1q_km + 1q_m == 1001q_m);
static_assert(10q_km / 5q_km == 2);
static_assert(100q_mm / 5q_cm == 2);
static_assert(10q_km / 2 == 5q_km);

static_assert(millimetre::symbol == "mm");
static_assert(centimetre::symbol == "cm");
static_assert(decimetre::symbol == "dm");
static_assert(kilometre::symbol == "km");

// mass

static_assert(1q_kg == 1000q_g);
static_assert(1q_t == 1000q_kg);

static_assert(kilogram::symbol == "kg");

// time

static_assert(1q_us == 1000q_ns);
static_assert(1q_ms == 1000q_us);
static_assert(1q_s == 1000q_ms);
static_assert(1q_min == 60q_s);
static_assert(1q_h == 60q_min);
static_assert(1q_h == 3600q_s);
static_assert(1q_d == 24q_h);
static_assert(1q_d == 86'400q_s);

static_assert(nanosecond::symbol == "ns");
static_assert(microsecond::symbol == "µs");
static_assert(millisecond::symbol == "ms");

// current

// temperature

// substance

// luminous intensity

/* ************** DERIVED DIMENSIONS WITH NAMED UNITS **************** */

// frequency

static_assert(1000q_mHz == 1q_Hz);
static_assert(1000q_Hz == 1q_kHz);
static_assert(1000q_kHz == 1q_MHz);
static_assert(1000q_MHz == 1q_GHz);
static_assert(1000q_GHz == 1q_THz);

static_assert(millihertz::symbol == "mHz");
static_assert(kilohertz::symbol == "kHz");
static_assert(megahertz::symbol == "MHz");
static_assert(gigahertz::symbol == "GHz");
static_assert(terahertz::symbol == "THz");

static_assert(2 / 1q_s == 2q_Hz);
static_assert(120 / 1q_min == 2q_Hz);
static_assert(1000 / 1q_s == 1q_kHz);
static_assert(1 / 1q_ms == 1q_kHz);
static_assert(3.2q_GHz == 3'200'000'000q_Hz);
static_assert(10q_Hz * 1q_min == 600);
static_assert(2 / 1q_Hz == 2q_s);

// force
static_assert(10q_kg * 10q_mps2 == 100q_N);
static_assert(100q_N / 1q_mps2 == 100q_kg);
static_assert(100q_N / 1q_kg == 100q_mps2);

// pressure

static_assert(10q_N / 10q_m2 == 1q_Pa);
static_assert(10q_N / 1q_Pa == 10q_m2);
static_assert(1q_Pa * 10q_m2 == 10q_N);

// energy

static_assert(1000q_mJ == 1q_J);
static_assert(1000q_J == 1q_kJ);
static_assert(1000q_kJ == 1q_MJ);
static_assert(1000q_MJ == 1q_GJ);

static_assert(millijoule::symbol == "mJ");
static_assert(kilojoule::symbol == "kJ");
static_assert(megajoule::symbol == "MJ");
static_assert(gigajoule::symbol == "GJ");

static_assert(10q_N * 10q_m == 100q_J);
static_assert(100q_J / 10q_m == 10q_N);
static_assert(100q_J / 10q_N == 10q_m);
static_assert(10q_Pa * 10q_m3 == 100q_J);
static_assert(100q_J / 10q_Pa == 10q_m3);
static_assert(100q_J / 10q_m3 == 10q_Pa);

// power

static_assert(1000q_mW == 1q_W);
static_assert(1000q_W == 1q_kW);
static_assert(1000q_kW == 1q_MW);
static_assert(1000q_MW == 1q_GW);

static_assert(milliwatt::symbol == "mW");
static_assert(kilowatt::symbol == "kW");
static_assert(megawatt::symbol == "MW");
static_assert(gigawatt::symbol == "GW");

static_assert(10q_J / 10q_s == 1q_W);
static_assert(1q_W * 10q_s == 10q_J);
static_assert(10q_J / 1q_W == 10q_s);

// electric charge

static_assert(10q_A * 10q_s == 100q_C);
static_assert(100q_C / 10q_A == 10q_s);
static_assert(100q_C / 10q_s == 10q_A);

// voltage

static_assert(10q_W / 10q_A == 1q_V);
static_assert(10q_W / 1q_V == 10q_A);
static_assert(1q_V * 10q_A == 10q_W);
static_assert(10q_J / 10q_C == 1q_V);
static_assert(10q_J / 1q_V == 10q_C);
static_assert(10q_C * 1q_V == 10q_J);

// capacitance

static_assert(10q_C / 10q_V == 1q_F);
static_assert(10q_C / 1q_F == 10q_V);
static_assert(10q_V * 1q_F == 10q_C);

/* ************** DERIVED DIMENSIONS IN TERMS OF BASE UNITS **************** */

// velocity

static_assert(std::is_same_v<decltype(1q_km / 1q_s), velocity<scaled_unit<ratio<1, 1, 3>, metre_per_second>, std::int64_t>>);

static_assert(10q_m / 5q_s == 2q_mps);
static_assert(10 / 5q_s * 1q_m == 2q_mps);
static_assert(1q_km / 1q_s == 1000q_mps);
// static_assert(1q_km / 1q_h == 1q_kmph);  // should not compile
static_assert(1.0q_km / 1q_h == 1q_kmph);
static_assert(1000.0q_m / 3600.0q_s == 1q_kmph);

static_assert(2q_kmph * 2q_h == 4q_km);
// static_assert(2q_kmph * 15q_min == 500q_m); // should not compile
static_assert(2q_kmph * 15.0q_min == 500q_m);
static_assert(2.0q_kmph * 15q_min == 500q_m);

static_assert(2q_km / 2q_kmph == 1q_h);
// static_assert(2000q_m / 2q_kmph == 1q_h); // should not compile
static_assert(quantity_cast<kilometre>(2000q_m) / 2q_kmph == 1q_h);

static_assert(detail::unit_text<dim_velocity, metre_per_second>() == "m/s");
static_assert(kilometre_per_hour::symbol == "km/h");

// acceleration

static_assert(10q_mps / 10q_s == 1q_mps2);
static_assert(10q_mps / 1q_mps2 == 10q_s);
static_assert(1q_mps2 * 10q_s == 10q_mps);

static_assert(detail::unit_text<dim_acceleration, metre_per_second_sq>() == "m/s²");

// area

static_assert(10q_m * 10q_m == 100q_m2);
static_assert(100q_m2 / 10q_m == 10q_m);
static_assert(10q_km * 10q_km == 100q_km2);
static_assert(1q_m2 == 10'000q_cm2);
static_assert(1q_ha == 10'000q_m2);

static_assert(detail::unit_text<dim_area, square_metre>() == "m²");

// volume

static_assert(1q_m * 1q_m * 1q_m == 1q_m3);
static_assert(10q_m2 * 10q_m == 100q_m3);
static_assert(10q_km * 10q_km * 10q_km == 1000q_km3);
static_assert(1q_m3 == 1'000'000q_cm3);
static_assert(1q_dm * 1q_dm * 1q_dm == 1q_l);
static_assert(1000q_l == 1q_m3);

static_assert(detail::unit_text<dim_volume, cubic_metre>() == "m³");

/* ************** DERIVED DIMENSIONS IN TERMS OF OTHER UNITS **************** */

static_assert(10q_N / 2q_m == 5q_Npm);
static_assert(10q_N / 5q_Npm == 2q_m);
static_assert(2q_m * 5q_Npm == 10q_N);

static_assert(detail::unit_text<dim_surface_tension, newton_per_metre>() == "N/m");

}  // namespace
