-- 
DELETE FROM `quest_request_items_locale` WHERE `ID` IN (12706,12716,12717,12718,12719,12724,12727) AND `locale` IN ("esES","esMX","frFr","ruRU");
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(12706,"frFR","J'étais certain que vous ne reviendriez pas ici en un seul morcerau, chevaller de la morte. Peut-étre que je vous avais sous-estimé.",18019),
(12706,"ruRU","Не думал, что ты вернешься живым с поля битвы, рыцарь смерти. Возможно, я тебя недооценил.",18019),
(12716,"esES","¿Has conseguido los objetos que te he pedido?",18019),
(12716,"esMX","¿Has conseguido los objetos que te he pedido?",18019),
(12716,"frFR","Avez-vous rassemblé les matériaux que je vous ai demandés ?",18019),
(12716,"ruRU","Ты все принес?",18019),
(12717,"esES","La caldera de peste está parada.",18019),
(12717,"esMX","La caldera de peste está parada.",18019),
(12717,"frFR","Le chaudron de peste semble endormi.",18019),
(12717,"ruRU","Варево в чумном котле лениво булькает.",18019),
(12718,"esES","La caldera de peste hace burbujas y agita su brebaje tóxico, echando un gas espeso.$b$b¿Tienes más calaveras de cruzado para poner dentro?",18019),
(12718,"esMX","La caldera de peste hace burbujas y agita su brebaje tóxico, echando un gas espeso.$b$b¿Tienes más calaveras de cruzado para poner dentro?",18019),
(12718,"frFR","La mixture toxique bouillonne dans le chaudron de peste, répandant une épaisse fumée aux alentours.$b$bAvez-vous plus de crânes de croisés à y jeter ?",18019),
(12718,"ruRU","Чумной котел булькает и расплескивает вокруг свое ядовитое содержимое, от которого поднимаются пары зеленоватого газа.$b$bЕсть ли у тебя еще несколько черепов рыцарей Света, чтобы добавить их в чумное варево?",18019),
(12719,"esES","¡No hay escapatoria!",18019),
(12719,"esMX","¡No hay escapatoria!",18019),
(12719,"frFR","Aucune issue de secours !",18019),
(12719,"ruRU","Спасения нет!",18019),
(12724,"esES","¡Devasta el bastión! ¡El horario está ahí!",18019),
(12724,"esMX","¡Devasta el bastión! ¡El horario está ahí!",18019),
(12724,"frFR","Mettez le fort à sac ! Le plan de route se trouve là-bas !",18019),
(12724,"ruRU","Обыщи всю крепость! Расписание хранится где-то там!",18019),
(12727,"esES","¿Qué pasa con Koltira?",18019),
(12727,"esMX","¿Qué pasa con Koltira?",18019),
(12727,"frFR","Qu’est-il advenu de Koltira ?",18019),
(12727,"ruRU","Какие новости от Кольтиры?",18019);

DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (12697,12698,12700,12701,12706,12714,12715,12716,12717,12718,12719,12720,12722,12723,12724,12725,12727,12738) AND `locale` IN ("esES","esMX","frFr","ruRU");
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(12697,"esES","Has luchado mucho para invadir el reino del Cosechador… Espera.$b$b<Gothik consulta sus notas.>$b$bDiscúlpame, $r. Cuesta cambiar las antiguas costumbres.$b$b¿Valanar te envió, entonces? Creo que eres bastante competente.$b$bTengo un regalo para los perros Escarlata. Uno que, estoy seguro, acelerará sus trabajos en las minas.",18019),
(12697,"esMX","Has luchado mucho para invadir el reino del Cosechador… Espera.$b$b<Gothik consulta sus notas.>$b$bDiscúlpame, $r. Cuesta cambiar las antiguas costumbres.$b$b¿Valanar te envió, entonces? Creo que eres bastante competente.$b$bTengo un regalo para los perros Escarlata. Uno que, estoy seguro, acelerará sus trabajos en las minas.",18019),
(12697,"frFr","Vous avez durement combattu pour envahir le royaume du moissonneur… Un instant.$b$b<Gothik regarde ses notes.>$b$bToutes mes excuses, $r. Difficile de se départir de ses vieilles habitudes.$b$bAinsi, Valanar vous envoie ? Je lui fais confiance pour juger de votre compétence.$b$bJ’ai un cadeau pour ces chiens écarlates. Un cadeau qui accélèrera leur travail dans les mines.",18019),
(12697,"ruRU","Вы сражались отчаянно, чтобы проникнуть в царство жнеца! Ох, погоди...$b$b<Готик пролистывает свои записи.>$b$bПрошу прощения, $r. Старые привычки неистребимы.$b$bПолагаю, тебя послал Валанар? Надеюсь, у него хватило ума послать кого-нибудь достаточно компетентного.$b$bВидишь ли, у меня есть небольшой подарок для жалких псов из Алого ордена. Сюрприз, который немного ускорит их работы на руднике.",18019),
(12698,"esES","Ahora saben que las minas ya no son seguras. Doblarán sus esfuerzos en retirarse y ¡nos las dejarán libres para nosotros!",18019),
(12698,"esMX","Ahora saben que las minas ya no son seguras. Doblarán sus esfuerzos en retirarse y ¡nos las dejarán libres para nosotros!",18019),
(12698,"frFr","Ils savent désormais que les mines ne sont plus sûres. Ils vont devoir faire deux fois plus d’efforts pour battre en retraite, et nous pourrons les attaquer par derrière !",18019),
(12698,"ruRU","Теперь они поймут, что на рудниках больше небезопасно, и постараются как можно быстрее убраться оттуда, забывая об осторожности!",18019),
(12700,"esES","Nos has hecho un buen servicio, caballero de la Muerte. Pocos de tus hermanos han sobrevivido nuestro ataque a los intrusos Escarlata. Eres uno de los más fuertes.$b$b<El príncipe Valanar asiente con la cabeza.>$b$bHacia el este, pasada la Mina Villa Refugio, está la costa llamada la Punta de la Luz por la Cruzada Escarlata. Un millar de soldados nos separa de sus barcos. ¿Insuperable? No lo creo...",18019),
(12700,"esMX","Nos has hecho un buen servicio, caballero de la Muerte. Pocos de tus hermanos han sobrevivido nuestro ataque a los intrusos Escarlata. Eres uno de los más fuertes.$b$b<El príncipe Valanar asiente con la cabeza.>$b$bHacia el este, pasada la Mina Villa Refugio, está la costa llamada la Punta de la Luz por la Cruzada Escarlata. Un millar de soldados nos separa de sus barcos. ¿Insuperable? No lo creo...",18019),
(12700,"frFr","Vous nous avez bien servi, chevalier de la mort. Peu de vos frères ont survécu à notre attaque initiale contre les intrus de la Croisade écarlate. Vous êtes l’un des plus puissants.$b$bÀ l’est d’ici, au-delà de la mine de Havre-Comté, se trouve la côte, appelée Halte de la Lumière par la Croisade écarlate. Un millier de soldats se trouvent entre nous et leurs navires. Insurmontable ? Pas vraiment...",18019),
(12700,"ruRU","Ты служишь нам верой и правдой, рыцарь смерти. Немногие из твоих собратьев вернулись назад после нашей первой стычки с захватчиками из Алого ордена, но ты оказался в числе сильнейших.$b$b<Принц Валанар одобрительно кивает.>$b$bК востоку отсюда, за Тихоземской шахтой есть побережье, которое Алый орден пафосно именует Заставой Света. Их флот защищают тысячи верных солдат. Скажешь, нам никогда их не одолеть? Ошибаешься...",18019),
(12701,"esES","¡La flota Escarlata al completo ha sido exterminada en cuestión de minutos! ¡Recibiré una mención de honor del Rey Exánime por esto! Todo lo que queda de la Cruzada Escarlata ahora son los ciudadanos de Nuevo Avalon.$b$bColocaré los ignitores y nigromantes en Villa Refugio inmediatamente. ¡Tú llevarás mi informe al Alto Señor!",18019),
(12701,"esMX","¡La flota Escarlata al completo ha sido exterminada en cuestión de minutos! ¡Recibiré una mención de honor del Rey Exánime por esto! Todo lo que queda de la Cruzada Escarlata ahora son los ciudadanos de Nuevo Avalon.$b$bColocaré los ignitores y nigromantes en Villa Refugio inmediatamente. ¡Tú llevarás mi informe al Alto Señor!",18019),
(12701,"frFr","Toute la flotte écarlate a coulé en quelques minutes ! Je vais recevoir une récompense du roi-liche pour ça ! Tout ce qui reste de la Croisade écarlate, désormais, ce sont les citoyens de la Nouvelle-Avalon.$b$bJe vais envoyer mes boute-flammes et mes nécromanciens sur Havre-Comté immédiatement. Vous, remettez mon rapport au généralissime !",18019),
(12701,"ruRU","Мы уничтожили весь флот Алого ордена в мгновение ока! Пожалуй, я заслужил одобрение Короля-лича! Нам осталось только разбить остатки армии Нового Авалона.$b$bЯ немедленно пошлю огненосцев и некромантов на Тихоземье. А ты лично доставишь мой доклад верховному лорду! ",18019),
(12706,"esES","<El alto señor Mograine lee el informe.>$b$b¿TODA la flota escarlata?$b$b<El alto señor Mograine asiente.>$b$bQue gran poder, $n... No había visto esa clase de dominio en años... Desde que mi padre portaba...$b$b<El alto señor Mograine sacude la cabeza.>$b$bNo importa...$b$bSí, tu recomendación, no sea que lo olvide.",18019),
(12706,"esMX","<El alto señor Mograine lee el informe.>$b$b¿TODA la flota escarlata?$b$b<El alto señor Mograine asiente.>$b$bQue gran poder, $n... No había visto esa clase de dominio en años... Desde que mi padre portaba...$b$b<El alto señor Mograine sacude la cabeza.>$b$bNo importa...$b$bSí, tu recomendación, no sea que lo olvide.",18019),
(12706,"ruRU","<Верховный лорд Могрейн просматривает доклад.>$b$bФлот Алого ордена ПОЛНОСТЬЮ уничтожен?$b$b<Верховный лорд Могрейн одобрительно качает головой.>$b$bКакая же сила скрыта в тебе, $n... Давно уже я не видел такой демонстрации превосходства... Пожалуй, с тех самых пор, как мой отец взял в руки...$b$b<Верховный лорд Могрейн взмахивает рукой.>$b$bВпрочем, это не важно...$b$bЧуть не забыл – вот твоя награда.",18019),
(12714,"esES","¡Villa Refugio es nuestra! Un millar de cadáveres yacen en el suelo esperando pacientemente renacer. ¡Ahora atacamos a nuestro enemigo con la fuerza renacida de la Plaga!$b$bLos necrófagos ya han empezado su ataque en Nuevo Avalon. Nuestras fuerzas avanzan detrás de ellos y han tomado la Cripta de los Recuerdos.",18019),
(12714,"esMX","¡Villa Refugio es nuestra! Un millar de cadáveres yacen en el suelo esperando pacientemente renacer. ¡Ahora atacamos a nuestro enemigo con la fuerza renacida de la Plaga!$b$bLos necrófagos ya han empezado su ataque en Nuevo Avalon. Nuestras fuerzas avanzan detrás de ellos y han tomado la Cripta de los Recuerdos.",18019),
(12714,"frFr","Havre-Comté est à nous ! Un millier de corps jonche le sol, attendant patiemment leur renaissance. Nous frappons maintenant notre ennemi avec la puissance éveillée du Fléau !$b$bLes goules ont déjà commencé leur assaut sur la Nouvelle-Avalon. Nos forces les ont suivies et ont pris la crypte du Souvenir.",18019),
(12714,"ruRU","Тихоземье пало! Тысячи трупов устилают землю, терпеливо ожидая воскрешения. Скоро мы нанесем решающий удар по нашему врагу со всей силой, на которую способна возрожденная Плеть!$b$bНаши вурдалаки уже начали осаду Нового Авалона; скоро к ним присоединятся и остальные войска, захватившие Склеп Воспоминаний.",18019),
(12715,"esES","Saludos, caballero de la Muerte. Soy el señor de sangre, Keleseth, gobernador de la parte sureste de Rasganorte. El Rey Exánime espera usar mis talentos para acabar con esta afrenta mortal a la Plaga. Me complace cumplir con todo lo que el Rey Exánime me pide. Claro está que un mar de infinitas almas para saciar mi sed endulzarán el trato, ¿no crees?",18019),
(12715,"esMX","Saludos, caballero de la Muerte. Soy el señor de sangre, Keleseth, gobernador de la parte sureste de Rasganorte. El Rey Exánime espera usar mis talentos para acabar con esta afrenta mortal a la Plaga. Me complace cumplir con todo lo que el Rey Exánime me pide. Claro está que un mar de infinitas almas para saciar mi sed endulzarán el trato, ¿no crees?",18019),
(12715,"frFr","Je vous salue, chevalier de la mort. Je suis le seigneur de sang Keleseth, dirigeant de la côte du sud-est du Norfendre. Le roi-liche a décidé de mettre mes talents à profit pour mettre un terme à cet affront mortel au Fléau. Comme pour tout ce que le roi-liche m’ordonne, je suis ravi de m’y plier. Bien sûr, une mer infinie d’âmes pour apaiser ma soif a grandement contribué à adoucir le marché.",18019),
(12715,"ruRU","Приветствую тебя, рыцарь смерти. Я – принц крови Келесет, правитель юго-восточных пределов Нордскола. Король-лич пожелал воспользоваться моими силами, чтобы покончить с жалким сопротивлением смертных, и я счастлив подчиниться воле моего господина. В конце концов, кто бы отказался насладиться страданиями бесчисленных тысяч душ?",18019),
(12716,"esES","¡Perfecto! Ahora dame un momento para poner todo en orden.",18019),
(12716,"esMX","¡Perfecto! Ahora dame un momento para poner todo en orden.",18019),
(12716,"frFr","Parfait ! Maintenant, laissez-moi un peu de temps pour mettre tout ça au point.",18019),
(12716,"ruRU","Отлично! Сейчас я все сделаю...",18019),
(12717,"esES","La caldera de peste cobra vida cuando pones las calaveras dentro.$b$bA los pocos segundos algunos viales de líquido negro flotan hasta arriba.",18019),
(12717,"esMX","La caldera de peste cobra vida cuando pones las calaveras dentro.$b$bA los pocos segundos algunos viales de líquido negro flotan hasta arriba.",18019),
(12717,"frFr","Le chaudron de peste prend vie lorsque vous jetez les crânes dedans.$b$bQuelques secondes plus tard, quelques fioles d’un liquide sombre flottent à sa surface.",18019),
(12717,"ruRU","Чумной котел подпрыгивает, жадно принимая ваше подношение.$b$bЧерез несколько секунд на поверхности появляются несколько флаконов с черной жидкостью.",18019),
(12718,"esES","La caldera de peste cobra vida cuando las calaveras se ponen dentro.$b$bA los pocos segundos, la caldera de peste te ofrece el oscuro y espumoso esplendor del brebaje especial de Noth.",18019),
(12718,"esMX","La caldera de peste cobra vida cuando las calaveras se ponen dentro.$b$bA los pocos segundos, la caldera de peste te ofrece el oscuro y espumoso esplendor del brebaje especial de Noth.",18019),
(12718,"frFr","Le chaudron de peste prend vie lorsque vous jetez les crânes dedans.$b$bQuelques secondes plus tard, le chaudron de peste contient la superbe cuvée spéciale de Noth, brune et mousseuse.",18019),
(12718,"ruRU","Чумной котел подпрыгивает, жадно принимая ваше подношение.$b$bЕще несколько секунд – и вы сможете насладиться темным и пенистым пойлом Нота!",18019),
(12719,"esES","El registro nos contará muchas cosas sobre los insectos Escarlatas.$b$b<Keleseth echa un vistazo rápido a las páginas del registro.>$b$bDatos sobre muertes, nacimientos, pero lo más importante, movimientos.$b$bMira aquí, $n, ya han enviado estas naves fuera. Déjame ver aquí… ¿Hacia dónde se dirigen?$b$b¿QUÉ? Es imposible. ¡Se dirigen hacia Rasganorte!$b$bJunto a las coordenadas figuran las palabras \"Alba Carmesí\".",18019),
(12719,"esMX","El registro nos contará muchas cosas sobre los insectos Escarlatas.$b$b<Keleseth echa un vistazo rápido a las páginas del registro.>$b$bDatos sobre muertes, nacimientos, pero lo más importante, movimientos.$b$bMira aquí, $n, ya han enviado estas naves fuera. Déjame ver aquí… ¿Hacia dónde se dirigen?$b$b¿QUÉ? Es imposible. ¡Se dirigen hacia Rasganorte!$b$bJunto a las coordenadas figuran las palabras \"Alba Carmesí\".",18019),
(12719,"frFr","Le registre va nous en apprendre beaucoup sur ces insectes écarlates.$b$b<Keleseth le feuillette.>$b$bTaux de mortalité et de natalité, mais surtout les mouvements.$b$bRegardez ici, $n. Ils ont déjà envoyé trois vaisseaux. Voyons… Où se rendent-ils ?$b$bQUOI ? C’est impossible. Ils font voile vers le Norfendre !$b$bÀ côté des coordonnées, les mots « Aube cramoisie » ont été écrits.",18019),
(12719,"ruRU","Этот реестр расскажет нам много всего интересного о ничтожествах, именующих себя Алым орденом.$b$b<Келесет лениво перелистывает страницы.>$b$bТут есть все – уровень смертности, рождаемости и самое главное – их перемещения.$b$bВидишь, $n – они отправили из Нового Авалона целых три корабля. И куда они направляются? Ну-ка, посмотрим...$b$b<Келесет бормочет под нос что-то про широту и долготу, вычисляя координаты.>$b$bЧТО? Этого не может быть! Они плывут в Нордскол!$b$bЗдесь, под координатами есть подпись: \"Багровый Рассвет.\" Что бы это могло означать?",18019),
(12720,"esES","¿Un despertar? ¡No sabes lo que dices, chico! ¿Qué clase de loco dejaría a su gente en medio de los fríos baldíos? Puede que este mensajero tenga la respuesta.",18019),
(12720,"esMX","¿Un despertar? ¡No sabes lo que dices, chico! ¿Qué clase de loco dejaría a su gente en medio de los fríos baldíos? Puede que este mensajero tenga la respuesta.",18019),
(12720,"frFr","Un éveil ? Vous dites n’importe quoi, jeune homme ! Quel genre de fou donnerait ses hommes en pâture au cœur même des terres gelées ? Alors, peut-être que ce courrier détient la réponse.",18019),
(12720,"ruRU","Пробуждение? Что за чепуху ты несешь, парень! Какой глупец поведет за собой людей в самое сердце ледяных пустошей? Возможно, курьер даст нам ответ на этот вопрос...",18019),
(12722,"esES","Eres bastante eficaz con esa espada, $n. Quizá, con el permiso del Rey Exánime, ¿estarías interesado en convertirte en uno de mis subordinados? Stratholme está buscando un nuevo alcalde.",18019),
(12722,"esMX","Eres bastante eficaz con esa espada, $n. Quizá, con el permiso del Rey Exánime, ¿estarías interesado en convertirte en uno de mis subordinados? Stratholme está buscando un nuevo alcalde.",18019),
(12722,"frFr","Vous êtes plutôt efficace avec cette lame, $n. Peut-être, si le roi-liche le permet, auriez-vous envie de devenir l’un de mes séides ? Stratholme a besoin d’un nouveau maire.",18019),
(12722,"ruRU","Ты прекрасно обращаешься с этим клинком, $n. Не желаешь стать моим прислужником – разумеется, с разрешения Короля-лича? Стратхольму нужен новый градоправитель.",18019),
(12723,"esES","Parece que aceptamos a cualquiera en la orden oscura estos días. Cuando me concedieron el don, las cosas eran distintas. ¡Muy distintas!$b$bY en lo que concierne a este mensajero...",18019),
(12723,"esMX","Parece que aceptamos a cualquiera en la orden oscura estos días. Cuando me concedieron el don, las cosas eran distintas. ¡Muy distintas!$b$bY en lo que concierne a este mensajero...",18019),
(12723,"frFr","On laisse rentrer n’importe qui dans l’ordre sombre de nos jours. Lorsque j’ai reçu ce don, les choses étaient différentes. Vraiment différentes !$b$bPour en revenir au courrier…",18019),
(12723,"ruRU","Ты посмотри – похоже, нынче в рыцарей смерти посвящают кого попало. Когда мне была дарована великая честь вступить в ряды Плети, все было совсем по-другому!$b$bА что касается курьера...",18019),
(12724,"esES","<Orbaz ojea el horario por encima.>$b$b¡Estos cretinos despreciables han estado ocupados! Rutas de patrullas del norte, rutas de patrullas del sur, rutas de patrullas del oeste y rutas de patrullas del este. Pero nada sobre las rutas de sus mensajeros. Espera un momento, ¿qué es esto? Parece una ruta de patrulla del oeste que viene de las Tierras de la Peste del Oeste. ¡Esta patrulla llegará hasta aquí hoy! Necesitaré tiempo para ingeniar un plan.",18019),
(12724,"esMX","<Orbaz ojea el horario por encima.>$b$b¡Estos cretinos despreciables han estado ocupados! Rutas de patrullas del norte, rutas de patrullas del sur, rutas de patrullas del oeste y rutas de patrullas del este. Pero nada sobre las rutas de sus mensajeros. Espera un momento, ¿qué es esto? Parece una ruta de patrulla del oeste que viene de las Tierras de la Peste del Oeste. ¡Esta patrulla llegará hasta aquí hoy! Necesitaré tiempo para ingeniar un plan.",18019),
(12724,"frFr","<Orbaz parcourt le plan de route.>$b$bCes crétins ont été bien occupés ! Des plans de route de patrouilles au nord, au sud, à l’ouest et à l’est, mais rien sur les trajets de leurs courriers. Une minute. Et ça, qu’est-ce que c’est ? On dirait une patrouille à l’ouest, qui viendrait des Maleterres de l’ouest ? Cette patrouille doit passer par ici aujourd’hui ! Il va falloir que nous nous préparions.",18019),
(12724,"ruRU","<Орбаз пролистывает расписание.>$b$bПохоже, у этих безмозглых слизняков полно работы! Расписание северных патрулей, восточных патрулей, южных патрулей, западных патрулей – и ни одного расписания курьеров! Минутку... А это еще что? Похоже на патрульный маршрут, проходящий возле Западных Чумных земель! В расписании он поставлен на сегодня! Надо все тщательно спланировать...",18019),
(12725,"esES","Has hecho una tontería al venir a buscarme. He fracasado. Tendrías que haberme dado por muerto. Ahora nos pueden matar a los dos.$b$b<Koltira sacude la cabeza>$b$bSomos caballeros de la Muerte de la Plaga. Esto infringe nuestro pacto de hermandad oscura.$b$bThassarian, ¡maldito necio!",18019),
(12725,"esMX","Has hecho una tontería al venir a buscarme. He fracasado. Tendrías que haberme dado por muerto. Ahora nos pueden matar a los dos.$b$b<Koltira sacude la cabeza>$b$bSomos caballeros de la Muerte de la Plaga. Esto infringe nuestro pacto de hermandad oscura.$b$bThassarian, ¡maldito necio!",18019),
(12725,"frFr","Vous n’auriez pas dû venir me chercher. J’ai échoué. Vous auriez dû me laisser pour mort, maintenant, nous allons peut-être être tués tous les deux.$b$b<Koltira secoue la tête.>$b$bNous sommes des chevaliers de la mort du Fléau. Cela va à l’encontre des engagements de la fraternité sombre.$b$bThassarian, espèce d’imbécile !",18019),
(12725,"ruRU","Глупо было идти мне на помощь. Я подвел нас всех. Надо было бросить меня на откуп судьбе – ведь теперь мы оба рискуем жизнью.$b$b<Кольтира качает головой.>$b$bМы – рыцари смерти, верные слуги Плети. Мы связаны законами нашего темного братства.$b$bТассариан, ты идиот!",18019),
(12727,"esES","¡Voy a alimentar a los necrófagos con la cabeza de este monstruo!$b$b<Thassarian lanza la cabeza a la habitación trasera.>$b$b¿Se escapó Koltira?$b$b<Thassarian hace una pausa.>$b$bSeguro que sí. Aquellas paredes no pueden pararlo.$b$bEs la hora de la venganza.",18019),
(12727,"esMX","¡Voy a alimentar a los necrófagos con la cabeza de este monstruo!$b$b<Thassarian lanza la cabeza a la habitación trasera.>$b$b¿Se escapó Koltira?$b$b<Thassarian hace una pausa.>$b$bSeguro que sí. Aquellas paredes no pueden pararlo.$b$bEs la hora de la venganza.",18019),
(12727,"frFr","Je donnerai la tête de ce monstre à manger aux goules !$b$b<Thassarian jette la tête dans l’arrière-salle.>$b$bKoltira a-t-il survécu ?$b$b<Thassarian fait une pause.>$b$bJe suis sûr que oui. Ces murs ne peuvent pas le retenir.$b$bIl est temps de régler nos comptes.",18019),
(12727,"ruRU","Я скормлю эту мерзкую голову вурдалакам!$b$b<Тассариан швыряет отрубленную голову в чулан.>$b$bКольтире удалось выбраться оттуда?$b$b<Тассариан умолкает.>$b$bНадеюсь, что да. Его не удержишь четырьмя стенами темницы.$b$bЧто ж, настало время расплаты!",18019),
(12738,"esES","Solo son de carne y hueso, no son rival para la Plaga.$b$bNo encontramos a ninguno de nuestros hermanos, pero tropezamos con algo especial.",18019),
(12738,"esMX","Solo son de carne y hueso, no son rival para la Plaga.$b$bNo encontramos a ninguno de nuestros hermanos, pero tropezamos con algo especial.",18019),
(12738,"frFr","Ils ne sont que de la chair et des os. Ils ne font pas le poids face au Fléau.$b$bNous n’avons trouvé aucun de nos frères, mais nous sommes tombés sur quelque chose de vraiment spécial.",18019),
(12738,"ruRU","Смертные из плоти и крови – не соперники рыцарям Плети.$b$bМы не смогли освободить наших братьев, но зато обнаружили нечто весьма любопытное.",18019);

UPDATE `quest_template_locale` SET `ObjectiveText1`="Necrófago escarlata convertido" WHERE `ID`=12698 AND (`locale`="esES" OR `locale`="esMX");
UPDATE `quest_template_locale` SET `ObjectiveText1`="Goule écarlate revenue" WHERE `ID`=12698 AND `locale`="frFR";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Обращено вурдалаков" WHERE `ID`=12698 AND `locale`="ruRU";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Defensor escarlata asesinado" WHERE `ID`=12701 AND (`locale`="esES" OR `locale`="esMX");
UPDATE `quest_template_locale` SET `ObjectiveText1`="Défenseur écarlate tué" WHERE `ID`=12701 AND `locale`="frFR";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Убито защитников Алого ордена" WHERE `ID`=12701 AND `locale`="ruRU";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Soldado de la Cruzada Escarlata asesinado",`ObjectiveText2`="Ciudadano de Nuevo Avalon asesinado" WHERE `ID`=12722 AND (`locale`="esES" OR `locale`="esMX");
UPDATE `quest_template_locale` SET `ObjectiveText1`="Soldat de la Croisade écarlate tué",`ObjectiveText2`="Habitant de la Nouvelle-Avalon tué" WHERE `ID`=12722 AND `locale`="frFR";
UPDATE `quest_template_locale` SET `ObjectiveText1`="Убито солдат Алого ордена",`ObjectiveText2`="Убито граждан Нового Авалона" WHERE `ID`=12722 AND `locale`="ruRU";
