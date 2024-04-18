const char json[] PROGMEM = R"JSON(
{
  "crops": [
    {
      "name": "Paddy",
      "temperature": {
        "min": 15,
        "max": 33
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "May",
        "June",
        "July",
        "August",
        "September",
        "October"
      ]
    },
    {
      "name": "Nagali",
      "temperature": {
        "min": 15,
        "max": 30
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "July",
        "August",
        "September"
      ]
    },
    {
      "name": "Jowar",
      "temperature": {
        "min": 20,
        "max": 30
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "June",
        "July",
        "August",
        "September",
        "October"
      ]
    },
    {
      "name": "Sugar-Cane",
      "temperature": {
        "min": 12,
        "max": 34
      },
      "humidity": {
        "min": 50,
        "max": 80
      },
      "soil_moisture": {
        "min": 50,
        "max": 76
      },
      "months_supported": [
        "October",
        "February",
        "March",
        "July"
      ]
    },
    {
      "name": "Groundnut",
      "temperature": {
        "min": 17,
        "max": 37
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 60,
        "max": 70
      },
      "months_supported": [
        "June",
        "July",
        "August",
        "September",
        "October"
      ]
    },
    {
      "name": "Bajra",
      "temperature": {
        "min": 20,
        "max": 30
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 49,
        "max": 77
      },
      "months_supported": [
        "February",
        "March",
        "April",
        "May"
      ]
    },
    {
      "name": "Urad",
      "temperature": {
        "min": 25,
        "max": 30
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 68,
        "max": 78
      },
      "months_supported": [
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August"
      ]
    },
    {
      "name": "Wheat",
      "temperature": {
        "min": 10,
        "max": 25
      },
      "humidity": {
        "min": 40,
        "max": 60
      },
      "soil_moisture": {
        "min": 40,
        "max": 60
      },
      "months_supported": [
        "November",
        "December",
        "January",
        "February"
      ]
    },
    {
      "name": "Gram",
      "temperature": {
        "min": 10,
        "max": 25
      },
      "humidity": {
        "min": 40,
        "max": 60
      },
      "soil_moisture": {
        "min": 40,
        "max": 60
      },
      "months_supported": [
        "November",
        "December",
        "January",
        "February"
      ]
    },
    {
      "name": "Lentil",
      "temperature": {
        "min": 10,
        "max": 25
      },
      "humidity": {
        "min": 40,
        "max": 60
      },
      "soil_moisture": {
        "min": 40,
        "max": 60
      },
      "months_supported": [
        "November",
        "December",
        "January",
        "February"
      ]
    },
    {
      "name": "Peas",
      "temperature": {
        "min": 15,
        "max": 25
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "November",
        "December",
        "January",
        "February"
      ]
    },
    {
      "name": "Peas",
      "temperature": {
        "min": 10,
        "max": 25
      },
      "humidity": {
        "min": 40,
        "max": 60
      },
      "soil_moisture": {
        "min": 40,
        "max": 60
      },
      "months_supported": [
        "November",
        "December",
        "January",
        "February"
      ]
    },
    {
      "name": "Potato",
      "temperature": {
        "min": 15,
        "max": 25
      },
      "humidity": {
        "min": 60,
        "max": 80
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "November",
        "December",
        "January",
        "February"
      ]
    },
    {
      "name": "Sugarcane",
      "temperature": {
        "min": 20,
        "max": 28
      },
      "humidity": {
        "min": 65,
        "max": 85
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "November",
        "December",
        "January",
        "February",
        "March"
      ]
    },
    {
      "name": "Banana",
      "temperature": {
        "min": 15,
        "max": 30
      },
      "humidity": {
        "min": 60,
        "max": 85
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "March",
        "April",
        "May",
        "June",
        "July"
      ]
    },
    {
      "name": "Perennial",
      "temperature": {
        "min": 15,
        "max": 30
      },
      "humidity": {
        "min": 60,
        "max": 85
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "March",
        "April",
        "May",
        "June",
        "July"
      ]
    },
    {
      "name": "Mango",
      "temperature": {
        "min": 15,
        "max": 35
      },
      "humidity": {
        "min": 60,
        "max": 85
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "March",
        "April",
        "May",
        "June",
        "July"
      ]
    },
    {
      "name": "Cashew",
      "temperature": {
        "min": 15,
        "max": 35
      },
      "humidity": {
        "min": 60,
        "max": 85
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "March",
        "April",
        "May",
        "June",
        "July"
      ]
    },
    {
      "name": "Guava",
      "temperature": {
        "min": 15,
        "max": 35
      },
      "humidity": {
        "min": 60,
        "max": 85
      },
      "soil_moisture": {
        "min": 60,
        "max": 80
      },
      "months_supported": [
        "March",
        "April",
        "May",
        "June",
        "July"
      ]
    },
    {
      "name": "Cotton",
      "temperature": {
        "min": 21,
        "max": 43
      },
      "humidity": {
        "min": 60,
        "max": 85
      },
      "soil_moisture": {
        "min": 78,
        "max": 91
      },
      "months_supported": [
        "March",
        "April",
        "May",
        "June",
        "July",
        "August"
      ]
    },
    {
      "name": "Tobacco",
      "temperature": {
        "min": 15,
        "max": 29
      },
      "humidity": {
        "min": 76,
        "max": 85
      },
      "soil_moisture": {
        "min": 60,
        "max": 70
      },
      "months_supported": [
        "April",
        "May",
        "June",
        "July",
        "August"
      ]
    },
    {
      "name": "Cauliflower",
      "temperature": {
        "min": 15,
        "max": 29
      },
      "humidity": {
        "min": 60,
        "max": 86
      },
      "soil_moisture": {
        "min": 78,
        "max": 86
      },
      "months_supported": [
        "May",
        "June",
        "July",
        "August"
      ]
    },
    {
      "name": "Hooga Booga Yaha Kuch Nahi Ooga",
      "temperature": {
        "min": 15,
        "max": 40
      },
      "humidity": {
        "min": 30,
        "max": 86
      },
      "soil_moisture": {
        "min": 1,
        "max": 6
      },
      "months_supported": [
        "April",
        "May",
        "June",
        "July",
        "August"
      ]
    },
    {
      "name": "Test Crop #2",
      "temperature": {
        "min": 15,
        "max": 40
      },
      "humidity": {
        "min": 50,
        "max": 86
      },
      "soil_moisture": {
        "min": 6,
        "max": 80
      },
      "months_supported": [
        "April",
        "May",
        "June",
        "July",
        "August"
      ]
    },
    {
      "name": "Grapes",
      "temperature": {
        "min": 23,
        "max": 42
      },
      "humidity": {
        "min": 69,
        "max": 86
      },
      "soil_moisture": {
        "min": 78,
        "max": 86
      },
      "months_supported": [
        "October",
        "November",
        "December",
        "Janaury"
      ]
    }
  ]
}
)JSON";