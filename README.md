Projet d'Algorithmique - Jeu OTHELLO

Commandes utiles après avoir cloné le projet :
- pour le rapport : make pdf (pour générer rapport.pdf)
                    make clean (pour le supprimer)
- pour le code source : make clean (suppression lib/ bin/ tests/.o src/.o doc/)
                        make all (générer l'exec othello qui se trouvera dans bin/ aussi générer la libothello.a qui se trouvera dans lib/)
                        make tests (générer les tests)
                        make doc (générer la doc)
- pour lancer le jeu (se placer dans bin/) : ./othello standard|tournoi blanc|noir

- mode standard : joueur Humain vs IA
- mode tournoi : IA vs IA
