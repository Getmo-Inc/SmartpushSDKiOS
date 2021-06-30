# SmartpushSDK iOS

# O que são Push Notifications? #

O serviço Apple Push Notification (APNs) é a peça central do recurso de notificações remotas. É um serviço robusto, seguro e altamente eficiente para os desenvolvedores de aplicativos propagarem informações para dispositivos iOS.

# O que as Push Notifications podem fazer? #

* Exibir uma mensagem.
* Tocar um som.
* Fornecer ações com as quais o usuário pode agir com ou sem abrir o aplicativo.
* Mostrar uma imagem ou outro tipo de mídia, até mesmo vídeos.
* Solicitar ao aplicativo para realizar alguma ação em segundo plano.

# Itens necessários antes de começar a configurar #

* Um dispositivo iOS de verdade, infelizmente as push notifications não funcionam no simulador.
* Programa de desenvolvedores da Apple, é necessário ter uma conta de desenvolvedor.
* É necessário criar uma conta no portal https://admin.getmo.com.br, é atrávez do portal que os push chegarão aos dispositivos.

## <a name="configurar_apns"></a> Configuração do APNS e implementação inicial passo a passo 

Passo 1: É necessário criar um projeto.

Passo 2: Adicionar a `Capabilities` de `Push`.  
![picture](https://cdn.getmo.com.br/images/capability.png)
![picture](https://cdn.getmo.com.br/images/capability_push.png)

Passo 3: Criar uma `key` na sua conta do Apple Member Center.
![picture](https://cdn.getmo.com.br/images/key.png)

Ative o APNS.
![picture](https://cdn.getmo.com.br/images/key_apns.png)

Neste momento, peço para que guarde a key `.p8` pois precisaremos dele mais tarde para adicionar no portal da SmartPush.

Agora vamos fazer a instalação da sdk no xcode:
## Instalação
**Obs:** Caso seu projeto já utilize SDK através do **.framework**, é necessário [remover-lo](#remove_old_sdk) antes de continuar.
1. Adicione este projeto como Submodulo de seu projeto Git, ou faça [Download](https://github.com/Getmo-Inc/SmartpushSDKiOS/archive/master.zip).
```
    $ git submodule add https://github.com/Getmo-Inc/SmartpushSDKiOS.git
```
<br>

Se você já tem o projeto acidionado como submodulo do git e precisa fazer update, acesse [aqui](#atualizar_sdk).

2. Abra a pasta **SmartpushSDKiOS** e arraste para dentro do seu projeto o arquivo **SmartpushSDK.xcodeproj**.
![](http://cdn.getmo.com.br/images/tutorial_ios/import_project.png)

<br>

3. Adicione os recursos da SDK no seu projeto através dos **Embedded Binaries**:
<img src="http://cdn.getmo.com.br/images/tutorial_ios/embedded.png" width="500">
- Selecione os 3 itens:
<img src="http://cdn.getmo.com.br/images/tutorial_ios/libs_choose.png" width="500">

<br>

4. Agora precisamos configurar o **Bundle Id** e a **assinatura** do seu app nos **App Extensions** da SDK:
- Selecione o arquivo **SmartpushSDK.xcodeproj** e depois o target **SmartpushNotificationExtension**.
- Agora substitua apenas o **YOUR-BUNDLE-ID** pelo **Bundle Id** do seu app. Exemplo **com.MyApp.SmartpushNotificationExtension**.
- Então substitua o **YOUR-VERSION** e **YOUR-BUILD** pela versão e build do seu app
- Configure a assinatura do **App Extension** conforme o seu app.
- Repita o procedimento para o target **SmartpushNotificationContent**.
![](http://cdn.getmo.com.br/images/tutorial_ios/extension.png)

<br>

5. Para fazer a ligação do app com as extensions **App Extensions** da SDK é necessário criar um grupo. 

Para criar um grupo, acesse o menu **Capabilities** e clique no botão "+":
<img src="http://cdn.getmo.com.br/images/tutorial_ios/appgroup_plus_button.png" width="500">

Então digite um nome para o grupo, esse será o valor da tag **SMARTPUSH_AppGroupKey**, veremos isso em seguida.

<img src="http://cdn.getmo.com.br/images/tutorial_ios/appgroup_create.png" width="500">

Deixe o grupo marcado e repita o processo para o **SmartpushNotificationExtension** e para o **SmartpushNotificationContent**:

<img src="http://cdn.getmo.com.br/images/tutorial_ios/app_group.png" width="500">

<br>

6. Caso sua aplicação seja em Swift, utilize um **Bridging-Header** para realizar a integração com o framework.
Clique [aqui](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html) para mais informações.

<br>

7. No arquivo **info.plist** do seu projeto adicione as seguintes chaves e seus respectivos valores:
- **SMARTPUSH_DevKey**
- **SMARTPUSH_AppKey**

O app key é encontrado no portal, acessando o menu "Apps".
![](http://cdn.getmo.com.br/images/tutorial_ios/appid_screen.png)

- **SMARTPUSH_AppGroupKey**: Chave criada no **App Groups**

- **SMARTPUSH_HitURL** (optional) - URL para receber hits de click e
recebimento; 
- **SMARTPUSH_UseUserLocation** (optional) - Atribuir valor "NO" somente para desabilitar o serviço de geolocalização;

<br>

Se você ainda não criou os certificados [clique aqui](#configurar_apns)

8. No arquivo **UIApplicationDelegate** implemente o delegate **SmartpushSDKDelegate**.

<br>

9. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didFinishLaunchingWithOptions**:

```
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

    //-----------SMARTPUSH SECTION-----------
    let shared = SmartpushSDK.sharedInstance()
    shared?.delegate = self
    shared?.didFinishLaunching(options: launchOptions)
    shared?.registerForPushNotifications()

    return true
}
```

<br>

10. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didFailToRegisterForRemoteNotificationsWithError**:

```
func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error:Error) {
    SmartpushSDK.sharedInstance().didFailToRegisterForRemoteNotificationsWithError(error)
}
```

<br>

11. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didRegisterForRemoteNotificationsWithDeviceToken**:

```
func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
    SmartpushSDK.sharedInstance().didRegisterForRemoteNotifications(withDeviceToken: deviceToken)
}
```

<br>

12. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didReceiveRemoteNotification**:

```
func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable: Any]) {
    SmartpushSDK.sharedInstance().didReceiveRemoteNotification(userInfo)
}
```

<br>

13. Ainda no arquivo **UIApplicationDelegate**, para compatibilidade como iOS8+, adicione o código abaixo no corpo do método **didRegisterUserNotificationSettings**:

```
func application(_ application: UIApplication, didRegister notificationSettings: UIUserNotificationSettings) {
    SmartpushSDK.sharedInstance().didRegister(notificationSettings)
}
```

<br>

14. Para capturar e tratar as mensagens push recebidas, adicione o código no corpo do método **onPushAccepted** no arquivo **UIApplicationDelegate**. Este método será chamado sempre que uma notificação for recebida ou quando o aplicativo for aberto ao clicar em uma notificação:

```
func onPushAccepted(_ push: [AnyHashable: Any]!, andOpenFromPush openFromPush: Bool) {
    print("Push: \(push)")
}

func onPushAccepted(_ push: [AnyHashable : Any]!, andOpenFromPush openFromPush: Bool, withUri uri: String!) {
    print("Push: \(push)")
}
```

<br>

15. Para que seu aplicativo receba as notificações pela central do iOS enquanto estiver em primeiro plano, importe **UserNotifications** e adicione o código no corpo do método **UIApplicationDelegate** no arquivo **UIApplicationDelegate**.

```
@available(iOS 10.0, *)
func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
    completionHandler([.alert, .badge, .sound])
}
```


**Pronto! A SDK SMARTPUSH está integrada a sua app! Sua app está pronta para receber mensagens push. Simples, não?**

<br>

## Gerenciando TAGs, Blacklist e Nearzones
### TAGs
A SDK provê mecanismos para que as apps possam criar e salvar tags, que depois serão utilizadas na filtragem dos conjuntos para envio direcionado de mensagens push através da API REST.

Para definir uma TAG de **String**, ou remove-la utilize o método abaixo:

```
SmartpushSDK.sharedInstance().setString("value", forTag: "key")
SmartpushSDK.sharedInstance().delStringTag(key)
```  
Exitem **5** tipos de TAGs que podem ser definidas:
- **String**
- **Number**
- **Boolean**
- **Date**
- **Array**

<br>

### Blacklist
A SDK provê mecanismos para que os usuários possam cancelar/ativar o recebimento de mensagens push. Para isso utilize o método abaixo:

```
SmartpushSDK.sharedInstance().blockUser(true)
```  

Para cancelar/ativar o recebimento de mensagens push, forneça um meio para que o usuário possa informar isso dentro do seu app. 

<br>

### Nearzones
A SDK provê mecanismos para que possam ser disparadas campanhas de mensagens push quando os usuários entrarem em regiões específicas.

Para monitorar e permitir o envio de mensagens push quando seus usuários ingressarem em determinadas áreas, utilize o método abaixo:

```
SmartpushSDK.sharedInstance().nearestZone(withLatitude: 0.0, andLongitude: 0.0)
```  

### Inbox - Acesso as últimas notificações

### Last Notifications
A SDK provê mecanismos para que os usuários possam acessar as últimas notificações através dos métodos abaixo:
O conteúdo do retorno é um objeto do tipo NSData.
```
    //Add observer get last notifications
    NotificationCenter.default.addObserver(self, selector: #selector(self.refreshData), name: NSNotification.Name.SmartpushSDKLastNotificationsObtained, object: nil)

    SmartpushSDK.sharedInstance().requestLastNotifications()

    let data = SmartpushSDK.sharedInstance().getLastNotifications()?.dataResponse!
``` 

### Mark as read
A SDK provê a funcionalidade de marcar uma notificação como lida. O parâmetro necessário é o id do push.

```
    SmartpushSDK.sharedInstance()?.markPush(asRead: obj.pushid)
``` 

### Mark all as read
A SDK provê a funcionalidade de marcar todas as notificações como lidas.

```
    SmartpushSDK.sharedInstance()?.markAllAsRead()
``` 

### Extra content
A SDK provê a funcionalidade acessar o conteúdo extra de uma notificação. Este é um conteúdo livre customizável pelo cliente.
```
    SmartpushSDK.sharedInstance()?.requestExtraContent(for: obj.pushid)
``` 

O último passo é adicionar os certificados no portal:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/certificados_portal.png)

<br>

## <a name="remove_old_sdk"></a>Removendo antiga SDK
Para remover a antiga SDK que utilizava o arquivo **.framework**, selecione **SmartpushSDK.framework** no seu projeto e **delete-o** movendo para a lixeira.

<img src="http://cdn.getmo.com.br/images/tutorial_ios/remove_old.png" width="400">

<br>

## <a name="atualizar_sdk"></a> Atualizar instalação da SDK 
Para atualizar a SDK é necessário fazer o procedimento a seguir:

Execute os comandos
```
    git submodule init
```
seguido por:
```
    git submodule update
```

e então vá para o diretório SmartpushSDKiOS
```
    cd SmartpushSDKiOS
```

e execute o comando
```
    git pull
```

pronto, a SDK está atualizada e agora é só compilar.
 

