import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

# Définir les adresses e-mail du destinataire et de l'expéditeur
sender_email = "fuster.virginie@free.fr"
receiver_email = "vfuster-@student.42perpignan.fr"

# Créer un objet MIMEMultipart
message = MIMEMultipart()

# Ajouter le sujet et le corps du message
message['Subject'] = 'Exemple d\'e-mail avec une pièce jointe'
message['From'] = sender_email
message['To'] = receiver_email
body = 'Bonjour,\n\nVeuillez trouver ci-joint un exemple de pièce jointe.\n\nCordialement,\nL\'expéditeur'
message.attach(MIMEText(body, 'plain'))

# Ajouter la pièce jointe
filename = "exemple.pdf"  # Nom du fichier
attachment = open("exemple.txt", "rb") # Ouvrir le fichier en mode binaire
p = MIMEBase('application', 'octet-stream')
p.set_payload((attachment).read())
encoders.encode_base64(p)
p.add_header('Content-Disposition', "attachment; filename= %s" % filename)
message.attach(p)

# Configurer le serveur SMTP et envoyer l'e-mail
smtp_server = "smtp.free.fr"
smtp_port = 993
login = "fuster.virginie"
password = "Georges01"
server = smtplib.SMTP(smtp_server, smtp_port)
server.starttls()
server.login(login, password)
text = message.as_string()
server.sendmail(sender_email, receiver_email, text)
server.quit()

