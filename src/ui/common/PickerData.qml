import QtQuick

QtObject {
    id: root

    property string filename
    property int index: 0

    property int fadein: 0
    property int volume: 100
    property int tempo: 100
    property int balance: 50

    function fromMusic(jsonData) {
        fromSound(jsonData)
        fadein = jsonData.num("fadein")
        return root
    }

    function fromSound(jsonData) {
        filename = jsonData.str("name")
        volume = jsonData.num("volume")
        tempo = jsonData.num("tempo")
        balance = jsonData.num("balance")
        return root
    }

    function toMusic(jsonData) {
        toSound(jsonData)
        jsonData.set("fadein", fadein)
        return root
    }

    function toSound(jsonData) {
        jsonData.set("name", filename)
        jsonData.set("volume", volume)
        jsonData.set("tempo", tempo)
        jsonData.set("balance", balance)
        return root
    }
}
