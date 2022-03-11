import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.15 as Kirigami

Kirigami.ApplicationWindow {
	// ID provides unique identifier to reference this element
	id: root
	title: "EasyRPG Editor"

	property var actor
	property var db

	// Initial page to be loaded on app load
	pageStack.initialPage: Text {
		text: `Hello World from ${db.actors.get(1).name}!`
	}

	Component.onCompleted: {
		db = project.database

		// Just some testing:
		console.log("Hello World!")

		// Accessing a term
		console.log(db.terms.actor_critical)

		// Setting an array element
		db.actors.get(1).parameters.maxhp[3] = 100;
		console.log(db.actors.get(1).parameters.maxhp)

		// Getting an actor and assigning it to a property
		actor = db.actors.get(2)
		actor.sayHello()

		// Accessing the parent of actor (database)
		console.log(actor.parent.items.get(1).description)

		// Output the start map name
		console.log(project.treemap.maps.get(project.treemap.start.party_map_id).name)
	}
}
